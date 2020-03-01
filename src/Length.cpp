#include "Length.h"
#include "LengthUnit.h"

bool Length::operator ==(const Length& rhs) const
{
    return this->amountInBaseUnit == rhs.amountInBaseUnit;
}

bool Length::operator !=(const Length& rhs) const
{
    return not this->operator ==(rhs);
}

Length::Length(const Amount& amount, const LengthUnit&unit):
amountInBaseUnit(unit.getAmountInBaseUnit(amount))
{
}
