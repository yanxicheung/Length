#ifndef HB2AC786C_B36A_4EC7_9028_FD326CE9347F
#define HB2AC786C_B36A_4EC7_9028_FD326CE9347F

#include "Amount.h"

#define DECL_VOLUME_SLUG(unit)  static const VolumeUnit & get##unit();

struct VolumeUnit
{
    Amount toAmountInBaseUnit(const Amount& amount) const;
    static const VolumeUnit& getBaseUnit() ;
private:
    VolumeUnit(unsigned int conversionFactor);

public:
    DECL_VOLUME_SLUG(TSP);
    DECL_VOLUME_SLUG(TBSP);
    DECL_VOLUME_SLUG(OZ);
private:
    unsigned int m_conversionFactor;
};
//////////////////////////////////////////////////////
#define TSP   (VolumeUnit::getTSP())
#define TBSP  (VolumeUnit::getTBSP())
#define OZ    (VolumeUnit::getOZ())


#endif /* HB2AC786C_B36A_4EC7_9028_FD326CE9347F */
