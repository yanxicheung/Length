#ifndef HF135910D_CD94_4729_A3F0_60CEE22F27B8
#define HF135910D_CD94_4729_A3F0_60CEE22F27B8

#include "Amount.h"
struct Mile;
struct Yard
{
    Yard(const Amount& amount);
    bool operator==(const Yard&rhs) const;
    bool operator!=(const Yard&rhs) const;

    bool operator==(const Mile&rhs) const;
    bool operator!=(const Mile&rhs) const;
private:
    friend class Mile;
    Amount amount;
};



#endif /* HF135910D_CD94_4729_A3F0_60CEE22F27B8 */
