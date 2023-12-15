#include "lottery.h"

using namespace trrne;

int lottery::bst(float *weights_arr, const size_t length) {
	if (length <= 0) {
		throw exception("karappo yanke");
	}

	vector<float> totals;
	float total = 0.f;
	for (int i = 0; i < length; ++i) {
		total += weights_arr[i];
		totals.push_back(total);
	}

	float r = rnd::randfloat(0, total);
	int top = int(length) - 1, bottom = 0;
	while (bottom < top) {
		int center = (bottom + top) / 2;
		if (r > totals[center]) {
			bottom = center + 1;
		} else {
			float p = center > 0 ? totals[size_t(center - 1)] : 0.f;
			if (r >= p) {
				return center;
			}
			top = center;
		}
	}
	return top;
}
