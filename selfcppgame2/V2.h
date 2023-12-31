#ifndef V2_H
#define V2_H

#include <math.h>
#include <string>
#include <sstream>
#include <ostream>

#include "numpp.h"

using namespace std;

namespace trrne {
	class V2 {
	public:
		double x, y;

		constexpr V2() noexcept : x(0.f), y(0.f) { }
		constexpr V2(double x, double y) noexcept : x(x), y(y) { }
		constexpr V2(const V2 &other) noexcept : x(other.x), y(other.y) { }

		constexpr V2 operator+(const V2 &other) const noexcept {
			return V2(x + other.x, y + other.y);
		}

		constexpr V2 operator+() const noexcept {
			return V2(+x, +y);
		}

		constexpr V2 &operator+=(const V2 &other) noexcept {
			x += other.x;
			y += other.y;
			return  *this;
		}

		constexpr V2 operator-(const V2 &other) const noexcept {
			return V2(x - other.x, y - other.y);
		}

		constexpr V2 operator-() const noexcept {
			return V2(-x, -y);
		}

		constexpr V2 &operator-=(const V2 &other) noexcept {
			x -= other.x;
			y -= other.y;
			return *this;
		}

		constexpr V2 operator*(const V2 &other) const noexcept {
			return V2(x * other.x, y * other.y);
		}

		constexpr V2 operator*(const double other) const noexcept {
			return V2(x * other, y * other);
		}

		constexpr V2 &operator*=(const V2 &other) noexcept {
			x *= other.x;
			y *= other.y;
			return *this;
		}

		constexpr V2 operator/(const V2 &other) const noexcept {
			return V2(x / other.x, y / other.y);
		}

		constexpr V2 operator/(const double other) const noexcept {
			return V2(x / other, y / other);
		}

		constexpr V2 &operator/=(const V2 &other) noexcept {
			x /= other.x;
			y /= other.y;
			return *this;
		}

		constexpr bool operator==(const V2 &other) const noexcept {
			return x == other.y && y == other.y;
		}

		constexpr bool operator!=(const V2 &other) const noexcept {
			return !(*this == other);
		}

		constexpr bool operator<(const V2 &other) noexcept {
			return x < other.x && y < other.y;
		}

		constexpr bool operator<=(const V2 &other) noexcept {
			return x <= other.x && y <= other.y;
		}

		constexpr bool operator>(const V2 &other) noexcept {
			return x > other.x && y > other.y;
		}

		constexpr bool operator>= (const V2 &other) noexcept {
			return x >= other.x && y >= other.y;
		}

		ostream &operator<<(ostream &os) noexcept {
			os << to_str();
			return os;
		}

		const string to_str(const int digit) const noexcept {
			stringstream ss;
			ss << "(" << numpp::floor(x, digit) << ", " << numpp::floor(y, digit) << ")";
			return ss.str();
		}

		const string to_str() const noexcept {
			return to_str(2);
		}

		operator const string() const noexcept {
			return to_str();
		}

		constexpr V2 floorf(const int digit) const noexcept {
			return V2(numpp::floor(x, digit), numpp::floor(y, digit));
		}

		const double magnitude() const noexcept {
			return sqrt(x * x + y * y);
		}

		const static double magnitude(V2 &a) noexcept {
			return a.magnitude();
		}

		const double distance(V2 &other) const noexcept {
			return (*this - other).magnitude();
		}

		const static double distance(V2 &a, V2 &b) noexcept {
			return a.distance(b);
		}

		const V2 normalize() const noexcept {
			return *this / magnitude();
		}

		const static V2 normalize(V2 &a) noexcept {
			return a.normalize();
		}

		const double dot(V2 &other) const noexcept {
			return x * other.x + y * other.y;
		}

		const static double dot(V2 &a, V2 &b) noexcept {
			return a.dot(b);
		}

		const double cross(V2 &other) const noexcept {
			return x * other.y - y * other.x;
		}

		const static double cross(V2 &a, V2 &b) noexcept {
			return a.cross(b);
		}

		const double angle(V2 &other) const noexcept {
			double lselfl = magnitude(),
				lotherl = other.magnitude();
			if (abs(lselfl + lotherl) < 1e-44f) {
				return 0.0;
			}
			return acos(dot(other) / lselfl / lotherl) * RAD_2_DEG;
		}

		const static double angle(V2 &a, V2 &b) noexcept {
			return a.angle(b);
		}

		const V2 to_polar() noexcept {
			return V2(x * cos(y), x * sin(y));
		}

		const static V2 to_polar(V2 &a) noexcept {
			return a.to_polar();
		}
	};
}

#endif // V2_H
