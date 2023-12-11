#include <memory>

using namespace std;

#ifndef TRRNE_HPP
#define TRRNE_HPP

template <class T, signed L>
static int length(T (&array_)[L])
{
    return sizeof(array_) / sizeof(T);
}

template <typename U, typename T>
std::unique_ptr<U> dynamic_unique_cast(std::unique_ptr<T> &&ptr)
{
    return std::unique_ptr<U>(dynamic_cast<U *>(ptr.release()));
}

#endif // TRRNE_HPP

// https://komorinfo.com/blog/cast-of-smart-pointers/