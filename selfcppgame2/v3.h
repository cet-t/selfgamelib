#ifndef V3_H
#define V3_H

#include <ostream>
#include <sstream>
#include <string>
#include <math.h>

#include "V2.h"
#include "numpp.h"

using namespace trrne;

namespace trrne {
	class V3 {
	public:
		float x, y, z;

		V3() noexcept;
		V3(float x, float y, float z) noexcept;

		void set(float x, float y, float z) noexcept;
		void set(V3 &other) noexcept;
		V3 get() const noexcept;

		const V3 operator+(const V3 &a) const noexcept;
		const V3 operator+() const noexcept;
		const V3 &operator+=(const V3 &a) noexcept;
		const V3 &operator+=(const float &a) noexcept;
		const V3 operator-(const V3 &a) const noexcept;
		const V3 operator-() const noexcept;
		const V3 &operator-=(const V3 &a) noexcept;
		const V3 &operator-=(const float &a) noexcept;
		const V3 operator*(const V3 &a) const noexcept;
		const V3 operator*(const float a) const noexcept;
		const V3 &operator*=(const V3 &a) noexcept;
		const V3 &operator*=(const float &a) noexcept;
		const V3 operator/(const V3 &a) const noexcept;
		const V3 operator/(const float a) const noexcept;
		const V3 &operator/=(const V3 &a) noexcept;
		const V3 &operator/=(const float &a) noexcept;
		const bool operator==(const V3 &a) const noexcept;
		const bool operator!=(const V3 &a) const noexcept;
		friend ostream &operator<<(ostream &os, const V3 &a) noexcept;
		operator string() const noexcept;
		const string to_str() const noexcept;
		const string to_str(const int digit) const noexcept;

		const V3 floorf(const int digit) const noexcept;

		const float magnitude() const noexcept;
		const float magnitude(const int digit) const noexcept;
		const static float magnitude(V3 &a) noexcept;
		const static float magnitude(V3 &a, const int digit) noexcept;

		const V3 normalize() noexcept;
		const static V3 normalize(V3 &a) noexcept;

		const float dot(V3 &other) const noexcept;
		const float dot(V3 &other, const int digit) const noexcept;
		const static float dot(V3 &a, V3 &b) noexcept;
		const static float dot(V3 &a, V3 &b, const int digit) noexcept;

		const float cross(V3 &other) const noexcept;
		const float cross(V3 &other, const int digit) const noexcept;
		const static float cross(V3 &a, V3 &b) noexcept;
		const static float cross(V3 &a, V3 &b, const int digit) noexcept;

		const float angle(V3 &other) const noexcept;
		const float angle(V3 &other, const int digit) const noexcept;
		const static float angle(V3 &a, V3 &b) noexcept;
		const static float angle(V3 &a, V3 &b, const int digit) noexcept;

		const V3 to_spherial() noexcept;
		const V3 to_spherial(const int digit) noexcept;
	};
}

#endif // V3_H
