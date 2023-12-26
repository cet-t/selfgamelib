#ifndef V2_H
#define V2_H

#include <math.h>
#include <string>
#include <sstream>
#include <ostream>

#include "numpp.h"

using namespace std;

namespace trrne
{
	class V2
	{
	public:
		float x, y;

		constexpr V2() noexcept
			: x(0.f), y(0.f) {}

		constexpr V2(float x, float y) noexcept
			: x(x), y(y) {}

		constexpr V2(const V2 &other) noexcept
			: x(other.x), y(other.y) {}

		constexpr V2 operator+(const V2 &other) const noexcept
		{
			return V2(x + other.x, y + other.y);
		}

		constexpr V2 operator+() const noexcept
		{
			return V2(+x, +y);
		}

		constexpr V2 &operator+=(const V2 &other) noexcept
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		constexpr V2 operator-(const V2 &other) const noexcept
		{
			return V2(x - other.x, y - other.y);
		}

		constexpr V2 operator-() const noexcept
		{
			return V2(-x, -y);
		}

		constexpr V2 &operator-=(const V2 &other) noexcept
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		constexpr V2 operator*(const V2 &other) const noexcept
		{
			return V2(x * other.x, y * other.y);
		}

		constexpr V2 operator*(const float other) const noexcept
		{
			return V2(x * other, y * other);
		}

		constexpr V2 &operator*=(const V2 &other) noexcept
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		constexpr V2 operator/(const V2 &other) const noexcept
		{
			return V2(x / other.x, y / other.y);
		}

		constexpr V2 operator/(const float other) const noexcept
		{
			return V2(x / other, y / other);
		}

		constexpr V2 &operator/=(const V2 &other) noexcept
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		constexpr bool operator==(const V2 &other) const noexcept
		{
			return x == other.y && y == other.y;
		}

		constexpr bool operator!=(const V2 &other) const noexcept
		{
			return !(*this == other);
		}

		constexpr bool operator<(const V2 &other) noexcept
		{
			return x < other.x && y < other.y;
		}

		constexpr bool operator<=(const V2 &other) noexcept
		{
			return x <= other.x && y <= other.y;
		}

		constexpr bool operator>(const V2 &other) noexcept
		{
			return x > other.x && y > other.y;
		}

		constexpr bool operator>=(const V2 &other) noexcept
		{
			return x >= other.x && y >= other.y;
		}

		ostream &operator<<(ostream &os) noexcept
		{
			os << to_str();
			return os;
		}

		const string to_str(const int digit) const noexcept
		{
			stringstream ss;
			ss << "(" << numpp::floor(x, digit) << ", " << numpp::floor(y, digit) << ")";
			return ss.str();
		}

		const string to_str() const noexcept
		{
			return to_str(2);
		}

		operator const string() const noexcept
		{
			return to_str();
		}

		constexpr V2 floorf(const int digit) const noexcept
		{
			return V2(numpp::floor(x, digit), numpp::floor(y, digit));
		}

		const float magnitude() const noexcept
		{
			return sqrtf(x * x + y * y);
		}

		const static float magnitude(V2 &a) noexcept
		{
			return a.magnitude();
		}

		const float distance(V2 &other) const noexcept
		{
			return (*this - other).magnitude();
		}

		const static float distance(V2 &a, V2 &b) noexcept
		{
			return a.distance(b);
		}

		const V2 normalize() const noexcept
		{
			return *this / magnitude();
		}

		const static V2 normalize(V2 &a) noexcept
		{
			return a.normalize();
		}

		const float dot(V2 &other) const noexcept
		{
			return x * other.x + y * other.y;
		}

		const static float dot(V2 &a, V2 &b) noexcept
		{
			return a.dot(b);
		}

		const float cross(V2 &other) const noexcept
		{
			return x * other.y - y * other.x;
		}

		const static float cross(V2 &a, V2 &b) noexcept
		{
			return a.cross(b);
		}

		const float angle(V2 &other) const noexcept
		{
			float lselfl = magnitude(),
				  lotherl = other.magnitude();
			if (fabsf(lselfl + lotherl) < 1e-44f)
			{
				return 0.f;
			}
			return acosf(dot(other) / lselfl / lotherl) * RAD_2_DEG;
		}

		const static float angle(V2 &a, V2 &b) noexcept
		{
			return a.angle(b);
		}

		const V2 to_polar() noexcept
		{
			return V2(x * cosf(y), x * sinf(y));
		}

		const static V2 to_polar(V2 &a) noexcept
		{
			return a.to_polar();
		}
	};
}

#endif // V2_H
