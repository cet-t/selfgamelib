#ifndef TRRNE_H
#define TRRNE_H

#include <memory>
#include <string>
#include <sstream>

#include "v2.h"

using namespace std;
using namespace trrne;

template <class T, signed N>
int length(T (&array)[N])
{
	return sizeof(array) / sizeof(T);
}

template <typename U, typename T>
unique_ptr<U> dynamic_unique_cast(unique_ptr<T> &&ptr)
{
	return unique_ptr<U>(dynamic_cast<U *>(ptr.release()));
}

string str(const bool a)
{
	return a ? "true" : "false";
}

template <typename T>
T sum(T *array, int length)
{
	T dst = 0;
	for (int i = 0; i < length; ++i)
	{
		dst += array[i];
	}
	return dst;
}

#endif // TRRNE_H

// https://komorinfo.com/blog/cast-of-smart-pointers/
