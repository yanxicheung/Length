#ifndef H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1
#define H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1

#include "Amount.h"
#include "AbstractLengthUnit.h"
#include "DelegatePointer.h"

#define DECL_UNIT_SLUG(unit)  static const LengthUnit & get##unit();

#define MILE   (LengthUnit::getMile())
#define YARD   (LengthUnit::getYard())
#define FEET   (LengthUnit::getFeet())
#define INCH   (LengthUnit::getInch())

struct LengthUnit : AbstractLengthUnit
{
    unsigned int toAmountInBaseUnit(const Amount&amount) const;
    const LengthUnit &getBaseUnit() const;
    DECL_UNIT_SLUG(Mile)
    DECL_UNIT_SLUG(Yard)
    DECL_UNIT_SLUG(Feet)
    DECL_UNIT_SLUG(Inch)
private:
    explicit LengthUnit(unsigned int conversionFactor, const LengthUnit& baseUnit);
    explicit LengthUnit();
    unsigned int getConversionFactor() const;
private:
    unsigned int conversionFactor;
    DelegatePointer< const AbstractLengthUnit* const> m_baseUnit;
};


#endif /* H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1 */



