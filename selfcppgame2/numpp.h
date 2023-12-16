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
		static float round(const float a, int digit) noexcept;
		static float round2(const float a) noexcept;

		static void clamp(float &a, const float min, const float max) noexcept;

		static float floor(const float a, const int digit) noexcept;

		static int cutail(const float a) noexcept;

		static int factorial(int n);
		/// n<=r
		static float permutation(const int n, const int r) noexcept;
		/// 0<=r<=n
		static int combination(const int n, const int r);

		static float sigmoid(const float x) noexcept;

		static float sigma(const int k, const int n) noexcept;
	};
}

#endif // MATHF_H
