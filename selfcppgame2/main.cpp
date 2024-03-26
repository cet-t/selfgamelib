#include <iostream>
#include <iomanip>
#include <format>
#include <string>
#include <print>

#include "trrne.h"
#include "v2.h"
//#include "v3.h"
//#include "crypto22.h"
#include "rnd.h"

#include "trrne.hpp"

using namespace std;
using namespace trrne;

int main() {
	//const size_t N = 4;
	//double weights[N] = { 0.2, 0.8, 0.7, 0.6 };
	//string names[N] = { "kara", "goma", "donguri", "ohagi" };
	//int counters[N] = { 0, 0, 0, 0 };
	//for (int i = 0; i < N; i++) {
	//	counters[trrne2::random::bst(weights)]++;
	//}
	//for (int i = 0; i < N; i++) {
	//	cout << names[i] << ": " << counters[i] << endl;
	//}

	unique_ptr<double[]> weights_ptr = make_unique<double[]>(3);
	for (int i = 0; i < 3; i++) {
		weights_ptr[i] = i;
		//cout << weights[i] << endl;
	}

	double weights_arr[3] = { .1,.2,.3 };
	for (int i = 0; i < 5; i++) {
		//cout << "array: " << trrne2::random::bst(weights_arr) << endl;
		cout << "ptr: " << trrne2::random::bst<3>(weights_ptr.get()) << endl;
	}
}
