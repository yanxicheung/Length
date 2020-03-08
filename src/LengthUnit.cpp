#include "LengthUnit.h"

struct AbstractLengthUnit
{
    virtual unsigned int getConversionFactor() const = 0;
    virtual const LengthUnit& getBaseUnit(const LengthUnit& unit) const = 0;
    virtual ~AbstractLengthUnit(){}
};

namespace
{
    const unsigned int BASE_UNIT_CONV_FACTOR = 1;

    struct BaseUnit:AbstractLengthUnit
    {
        unsigned int getConversionFactor() const
        {
            return BASE_UNIT_CONV_FACTOR;
        }

        const LengthUnit& getBaseUnit(const LengthUnit& unit) const
        {
            return unit;
        }
    };

    struct NonBaseUnit:AbstractLengthUnit
    {
        NonBaseUnit(unsigned int conversionFactor, const LengthUnit& refUnit):
        conversionFactor(conversionFactor),
        m_refUnit(refUnit){}

        unsigned int getConversionFactor() const
        {
            return m_refUnit.toAmountInBaseUnit(conversionFactor);
        }

        const LengthUnit& getBaseUnit(const LengthUnit& unit) const
        {
            return m_refUnit.getBaseUnit();
        }
    private:
        unsigned int conversionFactor;
        const LengthUnit&m_refUnit;
    };
}

LengthUnit::LengthUnit(unsigned int conversionFactor, const LengthUnit& baseUnit):
THIS(new NonBaseUnit(conversionFactor,baseUnit)){}

LengthUnit::LengthUnit():THIS(new BaseUnit()){}

unsigned int LengthUnit::toAmountInBaseUnit(const Amount&amount) const
{
    return amount * THIS->getConversionFactor();
}

const LengthUnit& LengthUnit::getBaseUnit() const
{
    return THIS->getBaseUnit(*this);
}

LengthUnit::~LengthUnit()
{
    delete THIS;
}
const LengthUnit & LengthUnit::getMile()
{
    static LengthUnit Mile(1760,getYard());
    return Mile;
}

const LengthUnit & LengthUnit::getYard()
{
    static LengthUnit Yard(3,getFeet());
    return Yard;
}

const LengthUnit & LengthUnit::getFeet()
{
    static LengthUnit Feet(12,getInch());
    return Feet;
}

const LengthUnit & LengthUnit::getInch()
{
    static LengthUnit Inch;
    return Inch;
}


