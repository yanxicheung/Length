#ifndef HD6991E28_128F_4CFC_9A53_E5853A2A5EDE
#define HD6991E28_128F_4CFC_9A53_E5853A2A5EDE

#include "Amount.h"

struct LengthUnit;

struct AbstractLengthUnit
{
   virtual unsigned int toAmountInBaseUnit(const Amount&amount) const = 0;
   virtual  const LengthUnit &getBaseUnit() const = 0;
   virtual ~AbstractLengthUnit(){}
};


#endif /* HD6991E28_128F_4CFC_9A53_E5853A2A5EDE */
