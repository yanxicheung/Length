#ifndef HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00
#define HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00

#include "Amount.h"

struct Length
{
    bool operator==(const Length&rhs) const;
    bool operator!=(const Length&rhs) const;
protected:
    Length(const Amount &amountInBaseUnit);
private:
    Amount amountInBaseUnit;
};

#endif /* HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00 */
