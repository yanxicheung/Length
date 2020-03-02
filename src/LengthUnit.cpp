#include "LengthUnit.h"

const LengthUnit& LengthUnit::getBaseUnit() const
{
    if(m_baseUnit == nullptr) return *this;
    return m_baseUnit->getBaseUnit();
}

LengthUnit::LengthUnit(unsigned int conversionFactor, const LengthUnit& baseUnit):
conversionFactor(conversionFactor),m_baseUnit(&baseUnit)
{
}

LengthUnit::LengthUnit():
conversionFactor(1),m_baseUnit(nullptr)
{
}

unsigned int LengthUnit::toAmountInBaseUnit(const Amount&amount) const
{
    return amount * getConversionFactor();
}

unsigned int LengthUnit::getConversionFactor() const
{
    if(m_baseUnit == nullptr) return 1;
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

