#include <iostream>
#include <string.h>

#include "trrne.h"
#include "v2.h"
#include "crypto22.h"

using namespace trrne;
using namespace std;

int i() {
	return 0;
}

int main() {
	V2 v1(1, 2), v2(3, -1);
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;
	cout << "+: " << +v1 << "(sign)" << endl;
	cout << "-: " << -v2 << "(sign)" << endl;
	cout << "+: " << v1 + v2 << endl;
	cout << "-: " << v1 - v2 << endl;
	cout << "*: " << v1 * v2 << endl;
	cout << "/: " << v1 / v2 << endl;
	cout << "+=: " << (v1 += v2) << endl;
	cout << "-=: " << (v1 -= v2) << endl;
	cout << "*=: " << (v1 *= v2) << endl;
	cout << "/=: " << (v1 /= v2) << endl;
	cout << "==: " << (v1 == v2) << endl;
	cout << "!=: " << (v1 != v2) << endl;

	auto src = "aiueokakikukeko";
	auto crypto = crypto22();
	auto e = crypto.en(src);
	auto d = crypto.de(e);
	cout << "src: " << src << endl;
	cout << "encrypt: " << e << endl;
	cout << "decrypt: " << d << endl;
}

