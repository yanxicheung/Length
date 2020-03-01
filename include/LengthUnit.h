#ifndef H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1
#define H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1

#include "Amount.h"

struct LengthUnit
{
    unsigned int getAmountInBaseUnit(const Amount&amount) const;
    static const LengthUnit & getMile();
    static const LengthUnit & getYard();
    static const LengthUnit & getFeet();
    static const LengthUnit & getInch();
private:
    explicit LengthUnit(unsigned int conversionFactor);
private:
    unsigned int conversionFactor;
};

#define MILE   (LengthUnit::getMile())
#define YARD   (LengthUnit::getYard())
#define FEET   (LengthUnit::getFeet())
#define INCH   (LengthUnit::getInch())

#endif /* H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1 */



