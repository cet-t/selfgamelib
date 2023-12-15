#ifndef TRRNE_H
#define TRRNE_H

#include <memory>

using namespace std;

template <class T, signed L>
static int length(T(&array_)[L]) {
	return sizeof(array_) / sizeof(T);
}

template <typename U, typename T>
std::unique_ptr<U> dynamic_unique_cast(std::unique_ptr<T> &&ptr) {
	return std::unique_ptr<U>(dynamic_cast<U *>(ptr.release()));
}

#endif // TRRNE_H

// https://komorinfo.com/blog/cast-of-smart-pointers/
