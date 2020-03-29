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

template<typename UNIT>
inline Quantity<UNIT>::Quantity(const Amount& amount, const UNIT& unit):
m_amountInBaseUnit(unit.toAmountInBaseUnit(amount))
{
}

template<typename UNIT>
inline bool Quantity<UNIT>::operator ==(const Quantity& rhs) const
{
    return m_amountInBaseUnit == rhs.m_amountInBaseUnit;
}

template<typename UNIT>
inline bool Quantity<UNIT>::operator !=(const Quantity& rhs) const
{
    return not this->operator ==(rhs);
}

template<typename UNIT>
inline Quantity<UNIT> Quantity<UNIT>::operator +(const Quantity& rhs) const
{
    Amount amountInBaseUnit = m_amountInBaseUnit + rhs.m_amountInBaseUnit;
    return Quantity(amountInBaseUnit,UNIT::getBaseUnit());
}

#endif /* HDBC7788A_4FC2_4F60_AE0A_F358C295AC4D */
