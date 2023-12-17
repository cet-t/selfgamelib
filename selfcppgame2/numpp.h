#ifndef MATHF_H
#define MATHF_H

#include <math.h>
#include <iostream>

using namespace std;

constexpr float PI = 3.141592f;
#define RAD_2_DEG (180 / PI)
#define DEG_2_RAD (PI / 180)

namespace trrne {
	class numpp {
	public:
		static float round(const float a, int digit) noexcept {
			return floorf((powf(a * 10, float(digit)) * 2 + 1) / 2) / powf(10, float(digit));
		}

		static float round2(const float a) noexcept {
			return float(a > 0.f ? long(a + .5f) : long(a - .5f));
		}

		static void clamp(float &a, const float min, const float max) noexcept {
			if (a < min) {
				a = min;
			} else if (a > max) {
				a = max;
			}
		}

		static float clamp(float a, const float min, const float max) noexcept {
			if (a < min) {
				return min;
			} else if (a > max) {
				return max;
			}
			return a;
		}

		static float floor(const float a, const int digit) noexcept {
			float mul = powf(10, float(digit));
			return floorf(a * mul) / mul;
		}

		static int cutail(const float a) noexcept {
			return int(floor(a, 0));
		}

		static int factorial(int n) {
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

		static float permutation(const int n, const int r) noexcept {
			return float(factorial(n) / factorial(n - r));
		}

		static int combination(const int n, const int r) {
			if (r <= 0 || r >= n) {
				throw exception();
			}
			return factorial(n) / factorial(r) / factorial(n - r);
		}

		static float sigmoid(const float x) noexcept {
			return 1 / (1 + expf(-x));
		}

		static float sigma(const int k, const int n) noexcept {
			int dst = 0;
			for (int i = k; i <= n; ++i) {
				dst += i;
			}
			return float(dst);
		}

		static bool twins(const float a, const float b, const float tolerance) noexcept {
			return fabsf(a + b) < tolerance;
		}

		static bool twins(const float a, const float b) noexcept {
			return twins(a, b, 1e-2f);
		}
	};
}

#endif // MATHF_H
