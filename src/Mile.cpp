#include "Mile.h"
#include "Yard.h"
Mile::Mile(const Amount& amount)
{
    this->amount = amount;
}

bool Mile::operator ==(const Mile& rhs) const
{
    return this->amount == rhs.amount;
}

bool Mile::operator !=(const Mile& rhs) const
{
    return not this->operator ==(rhs);
}

bool Mile::operator ==(const Yard& rhs) const
{
    return 1760*this->amount == rhs.amount;
}

bool Mile::operator !=(const Yard& rhs) const
{
    return not this->operator ==(rhs);
}
