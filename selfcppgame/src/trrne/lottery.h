#ifndef LOTTERY_HPP
#define LOTTERY_HPP

#include <bits/stdc++.h>

#include "rnd.h"

using namespace std;

namespace trrne
{
    class lottery
    {
    public:
        static int bst(const double *weights_arr, const int length)
        {
            if (length < 0)
            {
                throw exception();
            }

            vector<double> weights;
            for (int i = 0; i < length; ++i)
            {
                weights.push_back(weights_arr[i]);
            }

            double total = 0.0;
            vector<double> totals;
            for (int i = 0; i < length; ++i)
            {
                total += weights[i];
                totals.push_back(total);
            }

            double r = rnd::randdouble(0.0, total);
            int bottom = 0, top = length - 1;
            while (bottom < top)
            {
                int middle = (bottom + top) / 2;
                if (r > totals[middle])
                {
                    bottom = middle + 1;
                }
                else
                {
                    double p = middle > 0 ? totals[middle - 1] : 0.0;
                    if (r >= p)
                    {
                        return middle;
                    }
                    top = middle;
                }
            }
        }
    };
}

#endif // LOTTERY_HPP