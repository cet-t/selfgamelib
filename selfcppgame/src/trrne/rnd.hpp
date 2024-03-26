#ifndef RND_HPP
#define RND_HPP

#include <bits/stdc++.h>
#include "numpp.h"

enum RND
{
	RND_ALPHABET = 26,
	RND_NUMBER = 10,
	RND_MIXED = RND_ALPHABET + RND_NUMBER
};

inline static const double randdouble(double min_in, const double max_ex);
inline static const int randint(const int min_in, const int max_ex);
inline static void randchar(char *out, const int length);

#endif // RND_HPP
