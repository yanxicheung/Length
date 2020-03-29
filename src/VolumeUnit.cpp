#include "VolumeUnit.h"

Amount VolumeUnit::toAmountInBaseUnit(const Amount& amount) const
{
    return amount*m_conversionFactor;
}

const VolumeUnit& VolumeUnit::getBaseUnit()
{
    return VolumeUnit::getOZ();
}

VolumeUnit::VolumeUnit(unsigned int conversionFactor):
m_conversionFactor(conversionFactor)
{
}

const VolumeUnit & VolumeUnit::getTSP()
{
    static VolumeUnit tsp(1);
    return tsp;
}

const VolumeUnit & VolumeUnit::getTBSP()
{
    static VolumeUnit tbsp(3);
    return tbsp;
}

const VolumeUnit & VolumeUnit::getOZ()
{
    static VolumeUnit oz(6);
    return oz;
}

