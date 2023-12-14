#ifndef V2_HPP
#define V2_HPP

#include <math.h>
#include <string>
#include <sstream>

#include "mathf.hpp"

using namespace std;

namespace trrne
{
    class V2
    {
    public:
        float x, y;

        V2() : x(0.f), y(0.f) {}
        V2(float x, float y) : x(x), y(y) {}

        void set(float x, float y) noexcept;
        void set(V2 &other) noexcept;
        V2 get() const noexcept;

#pragma region operators

        const V2 operator+(const V2 &a) const noexcept;
        const V2 operator+() const noexcept;
        const V2 &operator+=(const V2 &a) noexcept;
        const V2 operator-(const V2 &a) const noexcept;
        const V2 operator-() const noexcept;
        const V2 &operator-=(const V2 &a_) noexcept;
        const V2 operator*(const V2 &a) const noexcept;
        const V2 operator*(const float a) const noexcept;
        const V2 &operator*=(const V2 &a) noexcept;
        const V2 operator/(const V2 &a) const noexcept;
        const V2 operator/(const float a) const noexcept;
        const V2 &operator/=(const V2 &a) noexcept;
        friend ostream &operator<<(ostream &os, const V2 &a) noexcept;
        operator string() const noexcept;
        const string to_str() const noexcept;
        const string to_str(int digit) const noexcept;

#pragma endregion

        static float angle(V2 a, V2 b, int digit = 1)
        {
            float lal = sqrtf(a.x * a.x + a.y * a.y),
                  lbl = sqrtf(b.x * b.x + b.y * b.y);
            float dot = a.x * b.x + a.y * b.y;
            return mathf::floor(acosf(dot / lal / lbl) * RAD_2_DEG, digit);
        }
    };
}

#endif // V2_HPP