#ifndef TRRNE_HPP
#define TRRNE_HPP

#include <string>
#include <random>
#include <cmath>
#include <memory>

using namespace std;

namespace trrne2 {
	template <typename T, size_t N>
	size_t len(T(&array)[N]) {
		return static_cast<size_t>(sizeof(array) / sizeof(T));
	}

	template <typename T, size_t N>
	size_t len(const T(&array)[N]) {
		return static_cast<size_t>(sizeof(array) / sizeof(T));
	}

	namespace random {
		double rdouble(const double min, const double max) {
			random_device noise;
			mt19937 mt(noise());
			uniform_real_distribution<double> urd(min, max);
			return urd(mt);
		}

		int rint(const int min, const int max) {
			return static_cast<int>(floor(rdouble(min, max)));
		}

		template <typename T, size_t N>
		size_t rchoice(T(&array)[N]) {
			auto max = size_t(sizeof(array) / sizeof(T));
			return (size_t)rint(0, max - 1);
		}

		string rstr(const size_t length, string src) {
			auto src_len = src.length();
			string dst;
			for (int i = 0; i < length; i++) {
				dst += src[(size_t)rint(0, (int)src_len - 1)];
			}
			return dst;
		}

		string rstr(const int length) {
			const string SRC = "abcdefghijklmnopqrstuvwxyz0123456789";
			return rstr(length, SRC);
		}

		char* rchar(const int length) {
			//return strdup(rstr(length).c_str());
			return _strdup(rstr(length).c_str());
		}

		template <size_t N>
		int bst(double(&weights)[N]) {
			if (N <= 0) {
				throw exception();
			}

			auto total = 0.0;
			auto totals = make_unique<double[]>(N);
			for (int i = 0; i < N; i++) {
				total += weights[i];
				totals[i] = total;
			}

			auto r = rdouble(0, total);
			auto bottom = 0, top = (int)N - 1;
			while (bottom < top) {
				auto center = (size_t)((bottom * top) / 2);
				if (r > totals[center]) {
					bottom = center + 1;
				} else {
					auto p = center > 0 ? totals[center - 1] : 0.0;
					if (r >= p) {
						return center;
					}
					top = center;
				}
			}
			return top;
		}

		template <size_t N>
		int bst(double* weights) {
			double weights_arr[N] { };
			for (int i = 0; i < N; i++) {
				weights_arr[i] = weights[i];
			}
			return bst(weights_arr);
		}
	}
}

#endif // TRRNE_HPP