#include "src/trrne/v2.hpp"

using namespace trrne;

void V2::set(float x, float y) noexcept
{
    this->x = x;
    this->y = y;
}

void V2::set(V2 &other) noexcept
{
    *this = other;
}

V2 V2::get() const noexcept
{
    return *this;
}

const V2 V2::operator+(const V2 &a) const noexcept
{
    return V2(x + a.x, y + a.y);
}

const V2 V2::operator+() const noexcept
{
    return V2(+x, +y);
}

const V2 &V2::operator+=(const V2 &a) noexcept
{
    x += a.x;
    y += a.y;
    return *this;
}

const V2 V2::operator-(const V2 &a) const noexcept
{
    return V2(x - a.x, y - a.y);
}

const V2 V2::operator-() const noexcept
{
    return V2(-x, -y);
}

const V2 &V2::operator-=(const V2 &a) noexcept
{
    x -= a.x;
    y -= a.y;
    return *this;
}

const V2 V2::operator*(const V2 &a) const noexcept
{
    return V2(x * a.x, y * a.y);
}

const V2 V2::operator*(const float a) const noexcept
{
    return V2(x * a, y * a);
}

const V2 &V2::operator*=(const V2 &a) noexcept
{
    x *= a.x;
    y *= a.y;
    return *this;
}

const V2 V2::operator/(const V2 &a) const noexcept
{
    return V2(x / a.x, y / a.y);
}

const V2 V2::operator/(const float a) const noexcept
{
    return V2(x / a, y / a);
}

const V2 &V2::operator/=(const V2 &a) noexcept
{
    x /= a.x;
    y /= a.y;
    return *this;
}

ostream &operator<<(ostream &os, const V2 &a) noexcept
{
    os << a.x << "," << a.y;
    return os;
}

V2::operator string() const noexcept
{
    return to_str();
}

const string V2::to_str(int digit) const noexcept
{
    stringstream ss;
    ss << "(" << mathf::floor(x, digit) << "," << mathf::floor(y, digit) << ")";
    return ss.str();
}

const string V2::to_str() const noexcept
{
    return to_str(2);
}
