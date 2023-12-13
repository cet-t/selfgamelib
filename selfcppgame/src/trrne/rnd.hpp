#include <mem.h>
#include <memory>
#include <random>
#include <stdio.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#ifndef RND_HPP
#define RND_HPP

namespace trrne
{
    // enum class RND
    // {
    //     ALPHABET = 26,
    //     NUMBER = 10,
    //     MIX = ALPHABET + NUMBER
    // };

    enum RND
    {
        RND_ALPHABET = 26,
        RND_NUMBER = 10,
        RND_MIX = RND_ALPHABET + RND_NUMBER
    };

    class rnd
    {
    public:
        static float randuniform(float min_, float max_ex_)
        {
            system_clock::duration now = system_clock::now().time_since_epoch();
            system_clock::rep ns = duration_cast<nanoseconds>(now).count();
            mt19937_64 mt64(ns);
            uniform_real_distribution<float> r(min_, max_ex_ - 1);
            return r(mt64);
        }

        static int randint(int min_, int max_ex_)
        {
            auto uniform = randuniform(min_, max_ex_ - 1);
            return (int)mathf::floor(uniform, 0);
        }

        static void randchar(char *out_, const int length_)
        {
            const char alphabets[RND_ALPHABET + 1] = {"abcdefghijklmnopqrstuvwxyz"};
            const char numbers[RND_NUMBER + 1] = {"0123456789"};
            cout << "--------------- sonomama ---------------" << endl;
            for (int i = 0; i < RND_ALPHABET + 1; ++i)
                cout << "ab: " << alphabets[i] << endl;
            for (int i = 0; i < RND_NUMBER + 1; ++i)
                cout << "no: " << numbers[i] << endl;
            cout << "----------------------------------------" << endl;

            cout << "--------------- renketugo ---------------" << endl;
            char cands[RND_ALPHABET + RND_NUMBER + 1] = {};
            strncat(cands, alphabets, RND_ALPHABET);
            strncat(cands, numbers, RND_NUMBER);
            cands[RND_ALPHABET + RND_NUMBER] = '\0';
            for (int i = 0; i < RND_ALPHABET + RND_NUMBER + 1; ++i)
                cout << i << ": " << cands[i] << endl;
            // cout << a << endl;
            cout << "----------------------------------------" << endl;

            char dst[length_];
            for (int i = 0; i < length_; ++i)
                dst[i] = cands[rnd::randint(0, RND_ALPHABET + RND_NUMBER)];
            dst[length_] = '\0';
            strncpy(out_, dst, length_);
            out_[length_ - 1] = '\0';
        }
    };
}

#endif // RND_HPP