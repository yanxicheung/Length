#ifndef HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00
#define HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00

#include "Amount.h"

const unsigned int BASE_CONV_FACTOR = 1;
const unsigned int INCH_CONV_FACTOR = BASE_CONV_FACTOR;
const unsigned int FEET_CONV_FACTOR = 12 * INCH_CONV_FACTOR;
const unsigned int YARD_CONV_FACTOR = 3 * FEET_CONV_FACTOR;
const unsigned int MILE_CONV_FACTOR = 1760 * YARD_CONV_FACTOR;

const unsigned int MILE = MILE_CONV_FACTOR;
const unsigned int YARD = YARD_CONV_FACTOR;
const unsigned int FEET = FEET_CONV_FACTOR;
const unsigned int INCH = INCH_CONV_FACTOR;

struct Length
{
    Length(const Amount &amount,unsigned int conversionFactor);
    bool operator==(const Length&rhs) const;
    bool operator!=(const Length&rhs) const;
private:
    Amount amountInBaseUnit;
};

#endif /* HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00 */
