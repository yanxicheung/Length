#ifndef HD081293D_161B_4244_9DDD_ACE9240C0B18
#define HD081293D_161B_4244_9DDD_ACE9240C0B18

#include "Quantity.h"
template<typename UNIT>
Quantity<UNIT>::Quantity(const Amount& amount, const UNIT& unit):
m_amountInBaseUnit(unit.toAmountInBaseUnit(amount))
{
}

template<typename UNIT>
bool Quantity<UNIT>::operator ==(const Quantity& rhs) const
{
    return m_amountInBaseUnit == rhs.m_amountInBaseUnit;
}

template<typename UNIT>
bool Quantity<UNIT>::operator !=(const Quantity& rhs) const
{
    return not this->operator ==(rhs);
}

template<typename UNIT>
Quantity<UNIT> Quantity<UNIT>::operator +(const Quantity& rhs) const
{
    Amount amountInBaseUnit = m_amountInBaseUnit + rhs.m_amountInBaseUnit;
    return Quantity(amountInBaseUnit,UNIT::getBaseUnit());
}

#endif /* HD081293D_161B_4244_9DDD_ACE9240C0B18 */
