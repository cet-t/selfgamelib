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
        V2(float x_, float y_) : x(x_), y(y_) {}

        void set(float x_, float y_)
        {
            x = x_;
            y = y_;
        }

        void set(V2 other_)
        {
            x = other_.x;
            y = other_.y;
        }

        V2 get()
        {
            return *this;
        }

#pragma region operators

        const V2 operator+(const V2 a_) const noexcept
        {
            return V2(x + a_.x, y + a_.y);
        }

        const V2 operator+() const noexcept
        {
            return V2(+x, +y);
        }

        const V2 operator+=(const V2 a_) noexcept
        {
            x += a_.x;
            y += a_.y;
            return *this;
        }

        const V2 operator-(const V2 a_) const noexcept
        {
            return V2(x - a_.x, y - a_.y);
        }

        const V2 operator-() const noexcept
        {
            return V2(-x, -y);
        }

        const V2 &operator-=(const V2 a_) noexcept
        {
            x -= a_.x;
            y -= a_.y;
            return *this;
        }

        const V2 operator*(const V2 a_) const noexcept
        {
            return V2(x * a_.x, y * a_.y);
        }

        const V2 operator*(const float a_) const noexcept
        {
            return V2(x * a_, y * a_);
        }

        const V2 &operator*=(const V2 a_) noexcept
        {
            x *= a_.x;
            y *= a_.y;
            return *this;
        }

        const V2 operator/(const V2 a_) const noexcept
        {
            return V2(x / a_.x, y / a_.y);
        }

        const V2 operator/(const float a_) const noexcept
        {
            return V2(x / a_, y / a_);
        }

        const V2 operator/=(const V2 a_) noexcept
        {
            x /= a_.x;
            y /= a_.y;
            return *this;
        }

        operator string() const noexcept
        {
            return to_string();
        }

        friend ostream &operator<<(ostream &os_, const V2 &a_);

#pragma endregion

        static float angle(V2 a_, V2 b_, int digit_ = 1)
        {
            float lal = sqrtf(a_.x * a_.x + a_.y * a_.y),
                  lbl = sqrtf(b_.x * b_.x + b_.y * b_.y);
            float dot = a_.x * b_.x + a_.y * b_.y;
            return mathf::floor(acosf(dot / lal / lbl) * RAD_2_DEG, digit_);
        }

        const string to_string() const noexcept
        {
            stringstream ss;
            ss << "(" << x << "," << y << ")";
            return ss.str();
        }

        const string to_string(int digit_) const noexcept
        {
            stringstream ss;
            ss << "(" << mathf::floor(x, digit_) << "," << mathf::floor(y, digit_) << ")";
            return ss.str();
        }
    };

    ostream &operator<<(ostream &os_, const V2 &a_)
    {
        os_ << a_.x << "," << a_.y;
        return os_;
    }
}

#endif // V2_HPP