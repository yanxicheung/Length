#include "LengthUnit.h"
LengthUnit::LengthUnit(unsigned int conversionFactor)
{
    this->conversionFactor = conversionFactor;
}
unsigned int LengthUnit::getConversionFactor() const
{
    return conversionFactor;
}


