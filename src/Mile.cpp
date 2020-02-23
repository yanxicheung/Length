#include "Mile.h"

Mile::Mile(const Amount& amount)
{
    this->amount = amount;
}

bool Mile::operator ==(const Mile& rhs)
{
    return this->amount == rhs.amount;
}

bool Mile::operator !=(const Mile& rhs)
{
    return not this->operator ==(rhs);
}
