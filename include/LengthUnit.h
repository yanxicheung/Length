#ifndef H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1
#define H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1

const unsigned int BASE_CONV_FACTOR = 1;
const unsigned int INCH_CONV_FACTOR = BASE_CONV_FACTOR;
const unsigned int FEET_CONV_FACTOR = 12 * INCH_CONV_FACTOR;
const unsigned int YARD_CONV_FACTOR = 3 * FEET_CONV_FACTOR;
const unsigned int MILE_CONV_FACTOR = 1760 * YARD_CONV_FACTOR;

struct LengthUnit
{
    explicit LengthUnit(unsigned int conversionFactor);
    unsigned int getConversionFactor() const;
private:
    unsigned int conversionFactor;
};

static LengthUnit MILE(MILE_CONV_FACTOR);
static LengthUnit YARD(YARD_CONV_FACTOR);
static LengthUnit FEET(FEET_CONV_FACTOR);
static LengthUnit INCH(INCH_CONV_FACTOR);

#endif /* H8CC5B1B1_F426_4D7A_B542_E8FCF9CB1FC1 */
