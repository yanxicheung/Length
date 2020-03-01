#include "LengthUnit.h"

namespace
{
    const unsigned int BASE_CONV_FACTOR = 1;
    const unsigned int INCH_CONV_FACTOR = BASE_CONV_FACTOR;
    const unsigned int FEET_CONV_FACTOR = 12 * INCH_CONV_FACTOR;
    const unsigned int YARD_CONV_FACTOR = 3 * FEET_CONV_FACTOR;
    const unsigned int MILE_CONV_FACTOR = 1760 * YARD_CONV_FACTOR;
}
LengthUnit::LengthUnit(unsigned int conversionFactor)
{
    this->conversionFactor = conversionFactor;
}

unsigned int LengthUnit::getAmountInBaseUnit(const Amount&amount) const
{
    return amount * conversionFactor;
}

const LengthUnit& LengthUnit::getMile()
{
    static LengthUnit Mile(MILE_CONV_FACTOR);
    return Mile;
}

const LengthUnit& LengthUnit::getYard()
{
    static LengthUnit Yard(YARD_CONV_FACTOR);
    return Yard;
}

const LengthUnit& LengthUnit::getFeet()
{
    static LengthUnit Feet(FEET_CONV_FACTOR);
    return Feet;
}

const LengthUnit& LengthUnit::getInch()
{
    static LengthUnit Inch(INCH_CONV_FACTOR);
    return Inch;
}
