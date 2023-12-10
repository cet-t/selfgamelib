#include <math.h>

using namespace std;
// using namespace trrne;

#define PI (3.14159)
#define RAD_2_DEG (180 / PI)
#define DEG_2_RAD (PI / 180)

#ifndef MATHF_HPP
#define MATHF_HPP

namespace trrne
{
    class mathf
    {
    public:
        inline static float round(float $a, int $digit)
        {
            return floorf((powf($a * 10, $digit) * 2 + 1) / 2) / powf(10, $digit);
        }

        inline static float round2(float $a)
        {
            return $a > 0.f ? (long)($a + .5f) : (long)($a - .5f);
        }

        inline static float clamp(float $a, int $min_include, int $max_exclude)
        {
            // return $a < $min_include ? $min_include : $a > $max_exclude ? $max_exclude : $a;
            if ($a < $min_include)
            {
                return $min_include;
            }
            else if ($a > $max_exclude)
            {
                return $max_exclude;
            }
            return $a;
        }

        inline static float floor(float $a, int $digit)
        {
            float mul = powf(10, $digit);
            return floorf($a * mul) / mul;
        }
    };
}

#endif // MATHF_HPP