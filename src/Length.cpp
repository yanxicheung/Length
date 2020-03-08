#include "Length.h"
#include "LengthUnit.h"

bool Length::operator ==(const Length& rhs) const
{
    return toAmountInBaseUnit() == rhs.toAmountInBaseUnit();
}

bool Length::operator !=(const Length& rhs) const
{
    return not this->operator ==(rhs);
}

Length::Length(const Amount& amount, const LengthUnit&unit):
amount(amount),m_unit(unit)
{

}

Length Length::operator +(const Length& rhs)
{
    Amount amountInBaseUnit = toAmountInBaseUnit() + rhs.toAmountInBaseUnit();
    return Length(amountInBaseUnit,m_unit.getBaseUnit());
}

Amount Length::toAmountInBaseUnit() const
{
   return m_unit.toAmountInBaseUnit(amount);
}
