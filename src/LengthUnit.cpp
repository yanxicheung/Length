#include "LengthUnit.h"
LengthUnit::LengthUnit(unsigned int conversionFactor)
{
    this->conversionFactor = conversionFactor;
}

unsigned int LengthUnit::getAmountInBaseUnit(const Amount&amount) const
{
    return amount * conversionFactor;
}
