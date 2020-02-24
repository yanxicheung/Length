#ifndef HEB53BCFD_9167_41D4_9344_B12F0EC135E6
#define HEB53BCFD_9167_41D4_9344_B12F0EC135E6
#include "Amount.h"
struct Yard;
struct Mile
{
    Mile(const Amount& amount);
    bool operator==(const Mile&rhs) const;
    bool operator!=(const Mile&rhs) const;

    bool operator==(const Yard&rhs) const;
    bool operator!=(const Yard&rhs) const;
private:
    Amount amount;
};

#endif /* HEB53BCFD_9167_41D4_9344_B12F0EC135E6 */
