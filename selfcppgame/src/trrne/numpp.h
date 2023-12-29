#ifndef MATHF_H
#define MATHF_H

#include <math.h>
#include <iostream>

using namespace std;

constexpr double PI = 3.141592f;
#define RAD_2_DEG (180 / PI)
#define DEG_2_RAD (PI / 180)

namespace trrne
{
	class numpp
	{
	public:
		static double round(double a, int digit)
		{
			return floorf((powf(a * 10, double(digit)) * 2 + 1) / 2) / powf(10, double(digit));
		}

		static double round2(double a)
		{
			return double(a > 0.f ? long(a + .5f) : long(a - .5f));
		}

		static void clamp(double &a, double min, double max)
		{
			if (a < min)
			{
				a = min;
			}
			else if (a > max)
			{
				a = max;
			}
		}

		static double clamp(double a, double min, double max)
		{
			if (a < min)
			{
				return min;
			}
			else if (a > max)
			{
				return max;
			}
			return a;
		}

		static double floor(double a, int digit)
		{
			double mul = powf(10, double(digit));
			return floorf(a * mul) / mul;
		}

		static int cutail(double a)
		{
			return int(floor(a, 0));
		}

		static int factorial(int n)
		{
			if (n < 0)
			{
				throw exception();
			}
			else if (n <= 1)
			{
				return n;
			}

			int dst = 1;
			for (int i = 1; i <= n; ++i)
			{
				dst *= i;
			}
			return dst;
		}

		static double permutation(int n, int r)
		{
			return factorial(n) / factorial(n - r);
		}

		static int combination(int n, int r)
		{
			if (r <= 0 || r >= n)
			{
				throw exception();
			}
			return factorial(n) / (factorial(r) * factorial(n - r));
		}

		static double sigmoid(double x) { return 1 / (1 + expf(-x)); }

		static double sigma(int k, int n)
		{
			int dst = 0;
			for (int i = k; i <= n; ++i)
			{
				dst += i;
			}
			return double(dst);
		}

		static bool twins(double a, double b, double tolerance) { return abs(a + b) < tolerance; }

		static bool twins(double a, double b) { return twins(a, b, 1e-2f); }
	};
}

#endif // MATHF_H
