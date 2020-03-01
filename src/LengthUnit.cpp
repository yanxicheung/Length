#include "LengthUnit.h"

namespace
{
#define CONV_FACTOR(unit)   unit##_CONV_FACTOR
#define DEF_CONV_FACTOR(unit,eq,factor,refUnit)         \
const unsigned int CONV_FACTOR(unit) = factor*CONV_FACTOR(refUnit);

    const unsigned int BASE_CONV_FACTOR = 1;
    DEF_CONV_FACTOR(Inch, =, 1, BASE)
    DEF_CONV_FACTOR(Feet, =, 12, Inch)
    DEF_CONV_FACTOR(Yard, =, 3, Feet)
    DEF_CONV_FACTOR(Mile, =, 1760, Yard)
}

const LengthUnit& LengthUnit::getBaseUnit()
{
    return getInch();
}

LengthUnit::LengthUnit(unsigned int conversionFactor)
{
    this->conversionFactor = conversionFactor;
}

unsigned int LengthUnit::getAmountInBaseUnit(const Amount&amount) const
{
    return amount * conversionFactor;
}

#define DEF_UNIT_SLUG(unit)                    \
const LengthUnit & LengthUnit::get##unit()     \
{                                               \
    static LengthUnit unit(CONV_FACTOR(unit)); \
    return unit;                               \
}

DEF_UNIT_SLUG(Mile)
DEF_UNIT_SLUG(Yard)
DEF_UNIT_SLUG(Feet)
DEF_UNIT_SLUG(Inch)

