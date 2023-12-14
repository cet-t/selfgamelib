#ifndef MATHF_HPP
#define MATHF_HPP

#include <math.h>

using namespace std;
// using namespace trrne;

#define PI (3.14159)
#define RAD_2_DEG (180 / PI)
#define DEG_2_RAD (PI / 180)

namespace trrne
{
    class mathf
    {
    public:
        inline static float round(float a_, int digit_)
        {
            return floorf((powf(a_ * 10, digit_) * 2 + 1) / 2) / powf(10, digit_);
        }

        inline static float round2(float a_)
        {
            return a_ > 0.f ? (long)(a_ + .5f) : (long)(a_ - .5f);
        }

        inline static void clamp(float *a_, const float min_include_, const float max_exclude_)
        {
            float *temp = new float;
            if (*a_ < min_include_)
            {
                *temp = min_include_;
            }
            else if (*a_ > max_exclude_)
            {
                *temp = max_exclude_;
            }
            a_ = temp;
            delete temp;
        }

        inline static float floor(float a_, int digit_)
        {
            float mul = powf(10, digit_);
            return floorf(a_ * mul) / mul;
        }

        inline static int kaijo(int n_)
        {
            if (n_ < 0)
            {
                return 0;
            }
            else if (n_ <= 2)
            {
                return n_;
            }

            for (int i = n_; i > 0; ++i)
            {
                n_ *= i;
            }
            return n_;
        }

        inline static int p(const int n_, const int r_)
        {
        }

        inline static int c(const int n_, const int r_)
        {
        }
    };
}

#endif // MATHF_HPP