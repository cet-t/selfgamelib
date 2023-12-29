#ifndef V2_H
#define V2_H

#include <bits/stdc++.h>

#include "numpp.h"

using namespace std;

namespace trrne
{
	class V2
	{
	public:
		double x, y;

		V2() : x(0.f), y(0.f) {}
		V2(double x, double y) : x(x), y(y) {}
		V2(V2 &other) : x(other.x), y(other.y) {}

		V2 operator+() const { return V2(+x, +y); }
		V2 operator-() const { return V2(-x, -y); }

		V2 operator+(V2 other) const { return V2(x + other.x, y + other.y); }
		V2 &operator+=(V2 &other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		V2 operator-(V2 other) const { return V2(x - other.x, y - other.y); }
		V2 &operator-=(const V2 &other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		V2 operator*(V2 other) const { return V2(x * other.x, y * other.y); }
		V2 operator*(double other) const { return V2(x * other, y * other); }
		V2 &operator*=(V2 &other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		V2 operator/(V2 other) const { return V2(x / other.x, y / other.y); }
		V2 operator/(double other) const { return V2(x / other, y / other); }
		V2 &operator/=(V2 &other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		bool operator==(V2 other) const { return x == other.y && y == other.y; }
		bool operator!=(V2 other) const { return !(*this == other); }
		bool operator<(V2 other) { return x < other.x && y < other.y; }
		bool operator<=(V2 other) { return x <= other.x && y <= other.y; }
		bool operator>(V2 other) { return x > other.x && y > other.y; }
		bool operator>=(V2 other) { return x >= other.x && y >= other.y; }

		ostream &operator<<(ostream &os)
		{
			os << str();
			return os;
		}

		const string str(const int digit) const
		{
			stringstream ss;
			ss << "(" << numpp::floor(x, digit) << ", " << numpp::floor(y, digit) << ")";
			return ss.str();
		}

		const string str() const { return str(2); }
		operator const string() const { return str(); }

		V2 floor(int digit) const { return V2(numpp::floor(x, digit), numpp::floor(y, digit)); }

		const double mag() const { return sqrtf(x * x + y * y); }
		const static double mag(V2 &a) { return a.mag(); }

		const V2 nor() const { return *this / mag(); }
		const static V2 nor(V2 &a) { return a.nor(); }

		const static double distance(V2 &a, V2 &b) { return (a - b).mag(); }
		const static double dot(V2 &a, V2 &b) { return a.x * b.x + a.y * b.y; }
		const static double angle(V2 &a, V2 &b) { return acos(dot(a, b) / a.mag() / b.mag()) * RAD_2_DEG; }

		const V2 to_polar() { return V2(x * cosf(y), x * sinf(y)); }
		const static V2 to_polar(V2 &a) { return a.to_polar(); }
	};
}

#endif // V2_H
