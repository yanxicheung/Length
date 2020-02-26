#ifndef HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00
#define HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00

#include "Amount.h"

const unsigned int BASE_UNIT = 1;
const unsigned int BASE_PER_INCH = BASE_UNIT;
const unsigned int BASE_PER_FEET = 12 * BASE_PER_INCH;
const unsigned int BASE_PER_YARD = 3 * BASE_PER_FEET;
const unsigned int BASE_PER_MILE = 1760 * BASE_PER_YARD;

const unsigned int MILE = BASE_PER_MILE;
const unsigned int YARD = BASE_PER_YARD;
const unsigned int FEET = BASE_PER_FEET;
const unsigned int INCH = BASE_PER_INCH;

struct Length
{
    Length(const Amount &amount,unsigned int conversionFactor);
    bool operator==(const Length&rhs) const;
    bool operator!=(const Length&rhs) const;
private:
    Amount amountInBaseUnit;
};

#endif /* HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00 */
