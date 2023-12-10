#ifndef TRRNE_HPP
#define TRRNE_HPP

template <class T, signed L>
static int length(T (&$array)[L])
{
    return sizeof($array) / sizeof(T);
}

#endif // TRRNE_HPP