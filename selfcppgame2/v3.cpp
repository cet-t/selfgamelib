#include "V3.h"

V3::V3() noexcept
	:x(0.f), y(0.f), z(0.f) { }

V3::V3(float x, float y, float z) noexcept
	: x(x), y(y), z(z) { }

void V3::set(float x, float y, float z) noexcept {
	this->x = x;
	this->y = y;
	this->z = z;
}

void V3::set(V3 &other) noexcept {
	x = other.x;
	y = other.y;
}

V3 V3::get() const noexcept {
	return *this;
}

const V3 V3::operator+(const V3 &a) const noexcept {
	return V3(x + a.x, y + a.y, z + a.z);
}

const V3 V3::operator+() const noexcept {
	return V3(+x, +y, +z);
}

const V3 &V3::operator+=(const V3 &a) noexcept {
	x += a.x;
	y += a.y;
	z += a.z;
	return *this;
}

const V3 &V3::operator+=(const float &a) noexcept {
	x += a;
	y += a;
	z += a;
	return *this;
}

const V3 V3::operator-(const V3 &a) const noexcept {
	return V3(x - a.x, y - a.y, z - a.z);
}

const V3 V3::operator-() const noexcept {
	return V3(-x, -y, -z);
}

const V3 &V3::operator-=(const V3 &a) noexcept {
	x -= a.x;
	y -= a.y;
	z -= a.z;
	return *this;
}

const V3 &V3::operator-=(const float &a) noexcept {
	x -= a;
	y -= a;
	z -= a;
	return *this;
}

const V3 V3::operator*(const V3 &a) const noexcept {
	return V3(x * a.x, y * a.y, z * a.z);
}

const V3 V3::operator*(const float a) const noexcept {
	return V3(x * a, y * a, z * a);
}

const V3 &V3::operator*=(const V3 &a) noexcept {
	x *= a.x;
	y *= a.y;
	z *= a.z;
	return *this;
}

const V3 &V3::operator*=(const float &a) noexcept {
	x *= a;
	y *= a;
	z *= a;
	return *this;
}

const V3 V3::operator/(const V3 &a) const noexcept {
	return V3(x / a.x, y / a.y, z / a.z);
}

const V3 V3::operator/(const float a) const noexcept {
	return V3(x / a, y / a, z / a);
}

const V3 &V3::operator/=(const V3 &a) noexcept {
	x /= a.x;
	y /= a.y;
	z /= a.z;
	return *this;
}

const V3 &V3::operator/=(const float &a) noexcept {
	x /= a;
	y /= a;
	z /= a;
	return *this;
}

const bool V3::operator==(const V3 &a) const noexcept {
	return x == a.x && y == a.y && z == a.z;
}

const bool V3::operator!=(const V3 &a) const noexcept {
	return !(*this == a);
}

ostream &trrne::operator<<(ostream &os, const V3 &a) noexcept {
	os << a.to_str(); // "(" << a.x << "," << a.y << "," << a.z << ")";
	return os;
}

V3::operator string() const noexcept {
	return to_str();
}

const string V3::to_str() const noexcept {
	return to_str(2);
}

const string V3::to_str(const int digit) const noexcept {
	stringstream ss;
	auto v = floorf(digit);
	ss << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return ss.str();
}

const V3 V3::floorf(const int digit) const noexcept {
	return V3(numpp::floor(x, digit), numpp::floor(y, digit), numpp::floor(z, digit));
}

const float V3::magnitude() const noexcept {
	return sqrtf(x * x + y * y + z * z);
}

const float V3::magnitude(const int digit) const noexcept {
	return numpp::floor(magnitude(), digit);
}

const float V3::magnitude(V3 &a) noexcept {
	return a.magnitude();
}

const float V3::magnitude(V3 &a, const int digit) noexcept {
	return a.magnitude(digit);
}

const V3 V3::normalize() noexcept {
	return V3(x / magnitude(), y / magnitude(), z / magnitude());
}

const V3 V3::normalize(V3 &a) noexcept {
	return a.normalize();
}

const float V3::dot(V3 &other) const noexcept {
	return x * other.x + y * other.y + z * other.z;
}

const float V3::dot(V3 &other, const int digit) const noexcept {
	return numpp::floor(V3::dot(other), digit);
}

const float V3::dot(V3 &a, V3 &b) noexcept {
	return a.dot(b);
}

const float V3::dot(V3 &a, V3 &b, const int digit) noexcept {
	return a.dot(b, digit);
}

const float V3::cross(V3 &other) const noexcept {
	return x * other.z - other.y * z - y * other.x;
}

const float V3::cross(V3 &other, const int digit) const noexcept {
	return numpp::floor(cross(other), digit);
}

const float V3::cross(V3 &a, V3 &b) noexcept {
	return a.cross(b);
}

const float V3::cross(V3 &a, V3 &b, const int digit) noexcept {
	return a.cross(b, digit);
}

const float V3::angle(V3 &other) const noexcept {
	float lal = magnitude(),
		lotherl = other.magnitude();
	if (fabsf(lal + lotherl) < 1e-44) {
		return 0.f;
	}
	return acosf(dot(other) / lal / lotherl) * RAD_2_DEG;
}

const float V3::angle(V3 &other, const int digit) const noexcept {
	return numpp::floor(angle(other), digit);
}

const float V3::angle(V3 &a, V3 &b) noexcept {
	return a.angle(b);
}

const float V3::angle(V3 &a, V3 &b, const int digit) noexcept {
	return a.angle(b, digit);
}

const V3 V3::to_spherial() noexcept {
	// https://www.comm.tcu.ac.jp/lab_thirano/edu/coordinate_systems-j.pdf
	float r = sqrtf(x * x + y * y + z * z),
		theta = powf(cosf(z / sqrtf(x * x + y * y * z * z)), -1),
		phi = powf(tanf(y / x), -1);
	return V3(r, theta, phi);
}

const V3 V3::to_spherial(const int digit) noexcept {
	return to_spherial().floorf(digit);
}

