#ifndef RND_HPP
#define RND_HPP

#include <memory>
#include <random>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <cstring>

#include "numpp.h"

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
	public:
		inline static const float randfloat(const float min_in, const float max_ex) noexcept {
			system_clock::duration now = system_clock::now().time_since_epoch();
			mt19937_64 mt(duration_cast<nanoseconds>(now).count());
			uniform_real_distribution<float> r(min_in, max_ex - 1);
			return r(mt);
		}

		inline static const int randint(const int min_in, const int max_ex) {
			system_clock::duration now = system_clock::now().time_since_epoch();
			mt19937_64 mt(duration_cast<nanoseconds>(now).count());
			uniform_int_distribution<int> r(min_in, max_ex - 1);
			return r(mt);
		}

		inline static void randchar(char *out, const int length) {
			constexpr char alphabets[RND_ALPHABET + 1] = { "abcdefghijklmnopqrstuvwxyz" },
				numbers[RND_NUMBER + 1] = { "0123456789" };

			char cands[RND_MIXED + 1] = {};
			strncat_s(cands, alphabets, RND_ALPHABET);
			strncat_s(cands, numbers, RND_NUMBER);
			cands[RND_MIXED] = '\0';
			char dst[RND_MIXED + 1] = {};
			for (int i = 0; i < length; ++i) {
				dst[i] = cands[randint(0, RND_MIXED)];
			}
			dst[length - 1] = '\0';
			memcpy(out, dst, length);
		}

		_declspec(deprecated) inline static char *randchar(const int length) {
			constexpr char alphabets[RND_ALPHABET + 1] = { "abcdefghijklmnopqrstuvwxyz" },
				numbers[RND_NUMBER + 1] = { "0123456789" };
			char cands[RND_MIXED + 1] = {};
			strncat_s(cands, alphabets, RND_ALPHABET);
			strncat_s(cands, numbers, RND_NUMBER);
			cands[RND_MIXED] = '\0';
			char dst[RND_MIXED + 1] = {};
			for (int i = 0; i < length; ++i) {
				dst[i] = cands[randint(0, RND_MIXED)];
			}
			dst[length - 1] = '\0';
			return dst;
		}
	};
}

#endif // RND_HPP
