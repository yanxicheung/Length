#include "Yard.h"
#include "Mile.h"
Yard::Yard(const Amount& amount)
{
    this->amount = amount;
}

bool Yard::operator ==(const Yard& rhs) const
{
    return this->amount == rhs.amount;
}

bool Yard::operator !=(const Yard& rhs) const
{
    return not this->operator ==(rhs);
}

bool Yard::operator ==(const Mile& rhs) const
{
    return rhs.operator ==(*this);
}

bool Yard::operator !=(const Mile& rhs) const
{
    return not this->operator ==(rhs);
}
