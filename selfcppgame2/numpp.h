#ifndef MATHF_H
#define MATHF_H

#include <math.h>
#include <iostream>

using namespace std;

constexpr double PI = 3.141592;
#define RAD_2_DEG (180 / PI)
#define DEG_2_RAD (PI / 180)

namespace trrne {
	class numpp {
	public:
		static double round(const double a, int digit) noexcept {
			return floor((pow(a * 10, digit) * 2 + 1) / 2, 0) / pow(10, digit);
		}

		static double round2(const double a) noexcept {
			return double(a > 0.f ? long(a + .5f) : long(a - .5f));
		}

		static void clamp(double &a, const double min, const double max) noexcept {
			if (a < min) {
				a = min;
			} else if (a > max) {
				a = max;
			}
		}

		static double clamp(double a, const double min, const double max) noexcept {
			if (a < min) {
				return min;
			} else if (a > max) {
				return max;
			}
			return a;
		}

		static double floor(const double a, const int digit) noexcept {
			double mul = pow(10, double(digit));
			return std::floor(a * mul) / mul;
		}

		static int cutail(const double a) noexcept {
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

		static double permutation(const int n, const int r) noexcept {
			return double(factorial(n) / factorial(n - r));
		}

		static int combination(const int n, const int r) {
			if (r <= 0 || r >= n) {
				throw exception();
			}
			return factorial(n) / factorial(r) / factorial(n - r);
		}

		static double sigmoid(const double x) noexcept {
			return 1 / (1 + exp(-x));
		}

		static double sigma(const int k, const int n) noexcept {
			int dst = 0;
			for (int i = k; i <= n; ++i) {
				dst += i;
			}
			return double(dst);
		}

		static bool twins(const double a, const double b, const double tolerance) noexcept {
			return abs(a + b) < tolerance;
		}

		static bool twins(const double a, const double b) noexcept {
			return twins(a, b, 1e-2f);
		}
	};
}

#endif // MATHF_H
