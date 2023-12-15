#ifndef LOTTERY_H
#define LOTTERY_H

#include <iostream>
#include <map>
#include <random>
#include <vector>

#include "rnd.h"

using namespace std;

namespace trrne {
	class lottery {
	public:
		static int bst(float *weights_arr, const size_t length);
	};
}

#endif // LOTTERY_H
