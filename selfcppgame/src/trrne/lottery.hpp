#include <iostream>
#include <vector>
#include <map>
#include <random>
// #include <string>

#include "rnd.hpp"

using namespace std;

#ifndef LOTTERY_HPP
#define LOTTERY_HPP

namespace trrne
{
    template <class T_SUB>
    class lottery_pair
    {
    private:
        vector<T_SUB> subjects;
        vector<float> weights;

    public:
        lottery_pair() {}
        lottery_pair(T_SUB $subject, float $weight)
        {
            // pairs = $pairs;
            subjects.push_back($subject);
            weights.push_back($weight);
        }

        void push_back(T_SUB $subject, float $weight)
        {
            subjects.push_back($subject);
            weights.push_back($weight);
        }

        const int size() const noexcept
        {
            return subjects.size();
        }

        const vector<T_SUB> get_subjects() const noexcept
        {
            return subjects;
        }

        const vector<float> get_weights() const noexcept
        {
            return weights;
        }
    };

    class lottery
    {
    public:
        static int binary_search_tree(const float *$weights_arr, const int $length)
        {
            float weights[$length];
            for (int i = 0; i < $length; i++)
            {
                weights[i] = $weights_arr[i];
            }

            float totals[$length], total = 0.f;
            for (int i = 0; i < $length; i++)
            {
                total += weights[i];
                totals[i] = total;
            }

            float random = rnd::randuniform(0, total);
            int bottom = 0, top = $length - 1;
            while (bottom < top)
            {
                int middle = (top + bottom) / 2;
                if (random > totals[middle])
                {
                    bottom = middle + 1;
                }
                else
                {
                    if (random >= (middle > 0 ? totals[middle - 1] : 0))
                    {
                        return middle;
                    }
                    top = middle;
                }
            }
            return top;
        }
    };
}

#endif // LOTTERY_HPP