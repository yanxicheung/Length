#ifndef HDBC7788A_4FC2_4F60_AE0A_F358C295AC4D
#define HDBC7788A_4FC2_4F60_AE0A_F358C295AC4D

#include "Amount.h"

template<typename UNIT>
struct Quantity
{
    Quantity(const Amount&amount,const UNIT&unit);
    bool operator==(const Quantity&rhs) const;
    bool operator!=(const Quantity&rhs) const;

    Quantity<UNIT> operator+(const Quantity&rhs) const;
private:
    Amount m_amountInBaseUnit;
};

#endif /* HDBC7788A_4FC2_4F60_AE0A_F358C295AC4D */
