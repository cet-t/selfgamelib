#ifndef V2_H
#define V2_H

#include <math.h>
#include <string>
#include <sstream>

#include "mathf.h"

using namespace std;

namespace trrne {
	class V2 {
	public:
		float x, y;

		V2() noexcept;
		V2(float x, float y) noexcept;

		void set(float x, float y) noexcept;
		void set(V2 &other) noexcept;
		V2 get() const noexcept;

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
		const bool operator==(const V2 &a) const noexcept;
		const bool operator!=(const V2 &a) const noexcept;
		friend ostream &operator<<(ostream &os, const V2 &a) noexcept;
		operator string() const noexcept;
		//operator float() const noexcept;
		const string to_str() const noexcept;
		const string to_str(const int digit) const noexcept;

		const float magnitude() const noexcept;
		const float magnitude(const int digit) const noexcept;
		const static float magnitude(V2 &a) noexcept;
		const static float magnitude(V2 &a, const int digit) noexcept;

		const V2 normalize() noexcept;
		const static V2 normalize(V2 &a) noexcept;

		const float dot(V2 &other) const noexcept;
		const float dot(V2 &other, const int digit) const noexcept;
		const static float dot(V2 &a, V2 &b) noexcept;
		const static float dot(V2 &a, V2 &b, const int digit) noexcept;

		const float cross(V2 &other) const noexcept;
		const float cross(V2 &other, const int digit) const noexcept;
		const static float cross(V2 &a, V2 &b) noexcept;
		const static float cross(V2 &a, V2 &b, const int digit) noexcept;

		const float angle(V2 &other) const noexcept;
		const float angle(V2 &other, const int digit) const noexcept;
		const static float angle(V2 &a, V2 &b) noexcept;
		const static float angle(V2 &a, V2 &b, const int digit) noexcept;

		const V2 to_polar() noexcept;
		const V2 to_polar(const int digit) noexcept;
	};
}

#endif // V2_H
