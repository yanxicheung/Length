#include "Mile.h"
const unsigned int YARDS_PER_MILE = 1760;
Mile::Mile(const Amount& amount):Length(amount*YARDS_PER_MILE)
{

}

