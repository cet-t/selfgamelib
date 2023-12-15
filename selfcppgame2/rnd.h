#ifndef RND_HPP
#define RND_HPP

#include <memory>
#include <random>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <cstring>

#include "mathf.h"

using namespace std;
using namespace chrono;
using namespace trrne;

namespace trrne {
	enum RND {
		RND_ALPHABET = 26,
		RND_NUMBER = 10,
		RND_MIXED = RND_ALPHABET + RND_NUMBER
	};

	class rnd {
	private:
	public:
		const static float randfloat(const float min_in, const float max_ex) noexcept;
		/*const static float randfloat(const float min_in, const float max_ex) noexcept {
			system_clock::duration now = system_clock::now().time_since_epoch();
			system_clock::rep ns = duration_cast<nanoseconds>(now).count();
			mt19937_64 mt64(ns);
			uniform_real_distribution<float> r(min_in, max_ex - 1);
			return r(mt64);
		}*/

		const static int randint(const int min_in, const int max_ex);
		/*static int randint(const int min_in, const int max_ex) {
			auto uniform = randfloat(min_in, max_ex - 1);
			return (int)mathf::floor(uniform, 0);
		}*/

		static void randchar(char *out, const int length);
		//const static char *randchar(char *out, const int length);
		/*static void randchar(char *out, const int length) {
			constexpr char alphabets[RND_ALPHABET + 1] = { "abcdefghijklmnopqrstuvwxyz" },
				numbers[RND_NUMBER + 1] = { "0123456789" };

			char cands[RND_ALPHABET + RND_NUMBER + 1] = {};
			strncat(cands, alphabets, RND_ALPHABET);
			strncat(cands, numbers, RND_NUMBER);
			cands[RND_ALPHABET + RND_NUMBER] = '\0';

			char dst[length] = {};
			for (int i = 0; i < length; ++i) {
				int choice = rnd::randint(0, RND_ALPHABET + RND_NUMBER);
				dst[i] = cands[choice];
			}
			dst[length] = '\0';
			memcpy(out, dst, length);
		}*/
	};
}

#endif // RND_HPP
