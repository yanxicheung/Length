#ifndef HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00
#define HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00

#include "Amount.h"

struct LengthUnit;

struct Length
{
    Length(const Amount &amount,const LengthUnit&unit);
    bool operator==(const Length&rhs) const;
    bool operator!=(const Length&rhs) const;
    Length operator+(const Length &rhs);
private:
    Amount toAmountInBaseUnit() const;

private:
    Amount amount;
    const LengthUnit &m_unit;
};

#endif /* HB7B07D22_8FDA_47C8_B6B8_7F95F0C29F00 */
