#include <random>
#include <stdio.h>
#include <time.h>
#include <chrono>

using namespace std;
using chrono::_V2::system_clock;

#ifndef RND_HPP
#define RND_HPP

namespace trrne
{
    enum class STRTYPE
    {
        MIX = 0,
        ALPHABET = 1,
        NUM = 2
    };

    class rnd
    {
    private:
        const char ALPHABETS[26] = {'abcdefghijklmnopqrstuvwxyz'};
        const char NUMBERS[10] = {'0123456789'};

    public:
        static float randuniform(float $min, float $max_ex)
        {
            system_clock::duration now = chrono::system_clock::now().time_since_epoch();
            system_clock::rep ns = chrono::duration_cast<chrono::nanoseconds>(now).count();
            mt19937_64 mt64(ns);
            uniform_real_distribution<float> r($min, $max_ex - 1);
            return r(mt64);
        }

        static int randint(int $min, int $max_ex)
        {
            auto uniform = randuniform($min, $max_ex - 1);
            return (int)mathf::floor(uniform, 0);
        }

        static char *randstr(STRTYPE type)
        {
            switch (type)
            {
            case STRTYPE::MIX:
                break;
            case STRTYPE::ALPHABET:
                break;
            case STRTYPE::NUM:
                break;
            default:
                break;
            }
        }
    };
}

#endif // RND_HPP