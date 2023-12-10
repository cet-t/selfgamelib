#include <math.h>
#include <string>
#include <sstream>

#include "mathf.hpp"

using namespace std;

#ifndef V2_HPP
#define V2_HPP

namespace trrne
{
    class V2
    {
    private:
        float x, y;

    public:
        V2() : x(0.f), y(0.f) {}
        V2(float $x, float $y) : x($x), y($y) {}

        void set(float $x, float $y)
        {
            x = $x;
            y = $y;
        }

        void set(V2 $other)
        {
            x = $other.x;
            y = $other.y;
        }

        V2 get()
        {
            return *this;
        }

#pragma region operators

        const V2 operator+(const V2 $a) const noexcept
        {
            return V2(x + $a.x, y + $a.y);
        }

        const V2 operator+() const noexcept
        {
            return V2(+x, +y);
        }

        const V2 operator+=(const V2 $a) noexcept
        {
            x += $a.x;
            y += $a.y;
            return *this;
        }

        const V2 operator-(const V2 $a) const noexcept
        {
            return V2(x - $a.x, y - $a.y);
        }

        const V2 operator-() const noexcept
        {
            return V2(-x, -y);
        }

        const V2 &operator-=(const V2 $a) noexcept
        {
            x -= $a.x;
            y -= $a.y;
            return *this;
        }

        const V2 operator*(const V2 $a) const noexcept
        {
            return V2(x * $a.x, y * $a.y);
        }

        const V2 operator*(const float $a) const noexcept
        {
            return V2(x * $a, y * $a);
        }

        const V2 &operator*=(const V2 $a) noexcept
        {
            x *= $a.x;
            y *= $a.y;
            return *this;
        }

        const V2 operator/(const V2 $a) const noexcept
        {
            return V2(x / $a.x, y / $a.y);
        }

        const V2 operator/(const float $a) const noexcept
        {
            return V2(x / $a, y / $a);
        }

        const V2 operator/=(const V2 $a) noexcept
        {
            x /= $a.x;
            y /= $a.y;
            return *this;
        }

        operator string() const noexcept
        {
            return to_string();
        }

        friend ostream &operator<<(ostream &$os, const V2 &$a);

#pragma endregion

        static float angle(V2 $a, V2 $b, int $digit = 1)
        {
            float lal = sqrtf($a.x * $a.x + $a.y * $a.y),
                  lbl = sqrtf($b.x * $b.x + $b.y * $b.y);
            float dot = $a.x * $b.x + $a.y * $b.y;
            return mathf::floor(acosf(dot / lal / lbl) * RAD_2_DEG, $digit);
        }

        const string to_string() const noexcept
        {
            stringstream ss;
            ss << "(" << x << "," << y << ")";
            return ss.str();
        }

        const string to_string(int $digit) const noexcept
        {
            stringstream ss;
            ss << "(" << mathf::floor(x, $digit) << "," << mathf::floor(y, $digit) << ")";
            return ss.str();
        }
    };

    ostream &operator<<(ostream &$os, const V2 &$a)
    {
        $os << $a.x << "," << $a.y;
        return $os;
    }
}

#endif // V2_HPP