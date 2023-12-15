#include "v2.h"

using namespace trrne;

V2::V2() noexcept
	: x(0.f), y(0.f) { }

V2::V2(float x, float y) noexcept
	: x(x), y(y) { }

//V2::V2(V2 &&other) = default;

void V2::set(float x, float y) noexcept {
	this->x = x;
	this->y = y;
}

void V2::set(V2 &other) noexcept {
	x = other.x;
	y = other.y;
}

V2 V2::get() const noexcept {
	return *this;
}

const V2 V2::operator+(const V2 &a) const noexcept {
	return V2(x + a.x, y + a.y);
}

const V2 V2::operator+() const noexcept {
	return V2(+x, +y);
}

const V2 &V2::operator+=(const V2 &a) noexcept {
	x += a.x;
	y += a.y;
	return *this;
}

const V2 V2::operator-(const V2 &a) const noexcept {
	return V2(x - a.x, y - a.y);
}

const V2 V2::operator-() const noexcept {
	return V2(-x, -y);
}

const V2 &V2::operator-=(const V2 &a) noexcept {
	x -= a.x;
	y -= a.y;
	return *this;
}

const V2 V2::operator*(const V2 &a) const noexcept {
	return V2(x * a.x, y * a.y);
}

const V2 V2::operator*(const float a) const noexcept {
	return V2(x * a, y * a);
}

const V2 &V2::operator*=(const V2 &a) noexcept {
	x *= a.x;
	y *= a.y;
	return *this;
}

const V2 V2::operator/(const V2 &a) const noexcept {
	return V2(x / a.x, y / a.y);
}

const V2 V2::operator/(const float a) const noexcept {
	return V2(x / a, y / a);
}

const V2 &V2::operator/=(const V2 &a) noexcept {
	x /= a.x;
	y /= a.y;
	return *this;
}

const bool V2::operator==(const V2 &a) const noexcept {
	return x == a.x && y == a.y;
}

const bool V2::operator!=(const V2 &a) const noexcept {
	return x != a.x && y != a.y;
}

ostream &trrne::operator<<(ostream &os, const V2 &a) noexcept {
	os << "(" << a.x << "," << a.y << ")";
	return os;
}

V2::operator string() const noexcept {
	return to_str();
}

//V2::operator float() const noexcept {
//	return magnitude();
//}

const string V2::to_str(const int digit) const noexcept {
	stringstream ss;
	ss << "(" << mathf::floor(x, digit) << "," << mathf::floor(y, digit) << ")";
	return ss.str();
}

const string V2::to_str() const noexcept {
	return to_str(2);
}

const float V2::magnitude() const noexcept {
	return sqrtf(x * x + y * y);
}

const float V2::magnitude(const int digit) const noexcept {
	return mathf::floor(magnitude(), digit);
}

const float V2::magnitude(V2 &a) noexcept {
	return a.magnitude();
}

const float V2::magnitude(V2 &a, const int digit) noexcept {
	return mathf::floor(a.magnitude(), digit);
}

const V2 V2::normalize() noexcept {
	return V2(x / magnitude(), y / magnitude());
}

const V2 V2::normalize(V2 &a) noexcept {
	return a.normalize();
}

const float V2::dot(V2 &other) const noexcept {
	return x * other.x + y * other.y;
}

const float V2::dot(V2 &other, const int digit) const noexcept {
	return mathf::floor(dot(other), digit);
}

const float V2::dot(V2 &a, V2 &b) noexcept {
	return a.dot(b);
}

const float V2::dot(V2 &a, V2 &b, const int digit) noexcept {
	return mathf::floor(a.dot(b), digit);
}

const float V2::cross(V2 &other) const noexcept {
	return x * other.y - y * other.x;
}

const float V2::cross(V2 &other, const int digit) const noexcept {
	return mathf::floor(cross(other), digit);
}

const float V2::cross(V2 &a, V2 &b) noexcept {
	return a.cross(b);
}

const float V2::cross(V2 &a, V2 &b, const int digit) noexcept {
	return a.cross(b, digit);
}

const float V2::angle(V2 &other) const noexcept {
	float lal = magnitude(), lbl = other.magnitude();
	float dot = x * other.x + y * other.y;
	return acosf(dot / lal / lbl) * RAD_2_DEG;
}

const float V2::angle(V2 &other, const int digit) const noexcept {
	return mathf::floor(angle(other), digit);
}

const float V2::angle(V2 &a, V2 &b) noexcept {
	return a.angle(b);
}

const float V2::angle(V2 &a, V2 &b, const int digit) noexcept {
	return a.angle(b, digit);
}

const V2 V2::to_polar() noexcept {
	return V2(x * cosf(y), x * sinf(y));
}

const V2 V2::to_polar(const int digit) noexcept {
	return V2(mathf::floor(to_polar().x, digit), mathf::floor(to_polar().y, digit));
}
