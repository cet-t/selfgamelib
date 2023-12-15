#include "mathf.h"

using namespace trrne;

float mathf::round(const float a, int digit) noexcept {
	return floorf((powf(a * 10, float(digit)) * 2 + 1) / 2) / powf(10, float(digit));
}

float mathf::round2(const float a) noexcept {
	return float(a > 0.f ? long(a + .5f) : long(a - .5f));
}

float &trrne::mathf::clamp(float &a, const float min, const float max) noexcept {
	if (a < min) {
		a = min;
	} else if (a > max) {
		a = max;
	}
	return a;
}

float mathf::floor(const float a, const int digit) noexcept {
	float mul = powf(10, float(digit));
	return floorf(a * mul) / mul;
}

int mathf::cutail(const float a) noexcept {
	return int(mathf::floor(a, 0));
}

int mathf::factorial(int n) {
	if (n < 0) {
		throw exception();
	} else if (n <= 1) {
		return n;
	}

	int dst = 1;
	for (int i = 1; i <= n; ++i) {
		dst *= i;
	}
	return dst;
}

float mathf::permutation(const int n, const int r) noexcept {
	return factorial(n) / factorial(n - r);
}

int mathf::combination(const int n, const int r) {
	if (r <= 0 || r >= n) {
		throw exception();
	}
	return factorial(n) / factorial(r) / factorial(n - r);
}
