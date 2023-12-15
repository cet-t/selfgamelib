#include "rnd.h"

const float rnd::randfloat(const float min_in, const float max_ex) noexcept {
	system_clock::duration now = system_clock::now().time_since_epoch();
	mt19937_64 mt(duration_cast<nanoseconds>(now).count());
	uniform_real_distribution<float> r(min_in, max_ex - 1);
	return r(mt);
}

const int rnd::randint(const int min_in, const int max_ex) {
	system_clock::duration now = system_clock::now().time_since_epoch();
	mt19937_64 mt(duration_cast<nanoseconds>(now).count());
	uniform_int_distribution<int> r(min_in, max_ex - 1);
	return r(mt);
}

void rnd::randchar(char *out, const int length) {
	const char alphabets[RND_ALPHABET + 1] = { "abcdefghijklmnopqrstuvwxyz" },
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
