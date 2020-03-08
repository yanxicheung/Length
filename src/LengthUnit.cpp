#include "LengthUnit.h"
namespace
{
    struct LengthBaseUnit:AbstractLengthUnit
    {
        LengthBaseUnit(const LengthUnit&baseUnit)
        :m_baseUnit(baseUnit){}
        unsigned int toAmountInBaseUnit(const Amount&amount) const
        {
            return amount;
        }
        const LengthUnit &getBaseUnit() const
        {
            return m_baseUnit;
        }
    private:
        const LengthUnit &m_baseUnit;
    };
}

LengthUnit::LengthUnit(unsigned int conversionFactor, const LengthUnit& baseUnit):
conversionFactor(conversionFactor),
m_isBaseUnit(false),
m_baseUnit(&baseUnit){}

LengthUnit::LengthUnit():
conversionFactor(1),
m_isBaseUnit(true),
m_baseUnit(new LengthBaseUnit(*this)){}

LengthUnit::~LengthUnit()
{
    if(m_isBaseUnit) delete m_baseUnit;
}

unsigned int LengthUnit::toAmountInBaseUnit(const Amount&amount) const
{
    return amount * getConversionFactor();
}

const LengthUnit& LengthUnit::getBaseUnit() const
{
    return m_baseUnit->getBaseUnit();
}

unsigned int LengthUnit::getConversionFactor() const
{
    return m_baseUnit->toAmountInBaseUnit(conversionFactor);
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


