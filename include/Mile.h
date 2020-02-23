#ifndef HEB53BCFD_9167_41D4_9344_B12F0EC135E6
#define HEB53BCFD_9167_41D4_9344_B12F0EC135E6
#include "Amount.h"

struct Mile
{
    Mile(const Amount& amount);
    bool operator==(const Mile&rhs);
    bool operator!=(const Mile&rhs);
private:
    Amount amount;
};

#endif /* HEB53BCFD_9167_41D4_9344_B12F0EC135E6 */
