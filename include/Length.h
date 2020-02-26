#ifndef HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00
#define HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00

#include "Amount.h"

const unsigned int YARDS_PER_MILE = 1760;
const unsigned int YARDS_PER_YARD = 1;

const unsigned int MILE = YARDS_PER_MILE;
const unsigned int YARD = YARDS_PER_YARD;

struct Length
{
    Length(const Amount &amount,unsigned int conversionFactor);
    bool operator==(const Length&rhs) const;
    bool operator!=(const Length&rhs) const;
private:
    Amount amountInBaseUnit;
};

#endif /* HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00 */
