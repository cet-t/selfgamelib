#ifndef TRRNE_H
#define TRRNE_H

#include <memory>
#include <string>
#include <sstream>

#include "v2.h"

using namespace std;
using namespace trrne;

template <class T, signed N>
static int length(T(&array)[N]) {
	return sizeof(array) / sizeof(T);
}

template <typename U, typename T>
unique_ptr<U> dynamic_unique_cast(unique_ptr<T>&& ptr) {
	return unique_ptr<U>(dynamic_cast<U*>(ptr.release()));
}

static string to_str(const bool a) {
	return a ? "true" : "false";
}

#endif // TRRNE_H

// https://komorinfo.com/blog/cast-of-smart-pointers/
