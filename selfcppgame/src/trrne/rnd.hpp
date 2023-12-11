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

#define ALPHABET (26 + 1)
#define NUMBER (10 + 1)
#define MIX (ALPHABET + NUMBER)

namespace trrne
{
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

        static void randchar(char *out_, const int type_, const int count_)
        {
            const char alphabets[ALPHABET] = {"abcdefghijklmnopqrstuvwxyz"},
                       numbers[NUMBER] = {"0123456789"};
            char cands[type_];
            auto choice = [&](char *chars)
            {
                unique_ptr<char[]> selected = make_unique<char[]>(count_);
                for (int i = 0; i < count_; ++i)
                {
                    selected[i] = cands[randint(0, type_ - 1)];
                }
                cout << selected.get() << endl;
                return selected.get();
            };

            switch (type_)
            {
            case MIX:
                strncat(cands, alphabets, ALPHABET);
                strncat(cands, numbers, NUMBER);
                cout << cands << endl;
                strncpy(out_, choice(cands), count_);
                break;
            case ALPHABET:
                break;
            case NUMBER:
                break;
            default:
                break;
            }
        }
    };
}

#endif // RND_HPP