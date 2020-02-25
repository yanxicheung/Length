#include "Yard.h"
const unsigned int YARDS_PER_YARD = 1;
Yard::Yard(const Amount& amount):Length(amount*YARDS_PER_YARD)
{
}
