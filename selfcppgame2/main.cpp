#include <iostream>
#include <string.h>

#include "trrne.h"
#include "v2.h"
#include "v3.h"
#include "crypto22.h"

using namespace trrne;
using namespace std;

//float add(int a, int b) {
//	return a + b;
//}
//float add(float a, float b) {
//	return a + b;
//}

int main() {
	//auto f = (float(*)(float, float)) & add;
	//cout << (*f)(12.8f, 12.8f) << endl;

	const auto HEADER = [](string title) { return "------- " + title + " -------"; };
	const string FOOTER = "--------------------\n";

	{
		cout << HEADER("Vector2D") << endl;
		V2 a(1, 2), b(3, -1);
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "+: " << +a << "(sign)" << endl;
		cout << "-: " << -b << "(sign)" << endl;
		cout << "+: " << a + b << endl;
		cout << "-: " << a - b << endl;
		cout << "*: " << a * b << endl;
		cout << "/: " << a / b << endl;
		cout << "+=: " << (a += b) << endl;
		cout << "-=: " << (a -= b) << endl;
		cout << "*=: " << (a *= b) << endl;
		cout << "/=: " << (a /= b) << endl;
		cout << "==: " << (a == b) << endl;
		cout << "!=: " << (a != b) << endl;
		cout << "正規化: " << a.normalize() << "(" << V2::normalize(a) << ")" << endl;
		cout << "ノルム: " << a.magnitude() << "(" << V2::magnitude(a) << ")" << endl;
		cout << "内積: " << a.dot(b) << "(" << V2::dot(a, b) << ")" << endl;
		cout << "外積: " << a.cross(b) << "(" << V2::cross(a, b) << ")" << endl;
		cout << "切り捨て: " << a.floorf(2) << endl;
		cout << "極座標からの変換: " << a.to_polar() << endl;
		cout << FOOTER << endl;
	}

	{
		cout << HEADER("CRYPTO") << endl;
		const auto src = "aiueokakikukeko";
		auto crypto = crypto22();
		string e = crypto.en(src), d = crypto.de(e);
		cout << "src: " << src << endl;
		cout << "encrypt: " << e << endl;
		cout << "decrypt: " << d << endl;
		cout << FOOTER << endl;
	}

	{
		cout << HEADER("Vector3D") << endl;
		V3 a(1, 2, 4), b(-4, 3, -1);
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "+: " << +a << "(sign)" << endl;
		cout << "-: " << -b << "(sign)" << endl;
		cout << "+: " << a + b << endl;
		cout << "-: " << a - b << endl;
		cout << "*: " << a * b << endl;
		cout << "/: " << a / b << endl;
		cout << "+=: " << (a += b) << endl;
		cout << "-=: " << (a -= b) << endl;
		cout << "*=: " << (a *= b) << endl;
		cout << "/=: " << (a /= b) << endl;
		cout << "==: " << (a == b) << endl;
		cout << "!=: " << (a != b) << endl;
		cout << "正規化: " << a.normalize() << "(" << V3::normalize(a) << ")" << endl;
		cout << "ノルム: " << a.magnitude() << "(" << V3::magnitude(a) << ")" << endl;
		cout << "内積: " << a.dot(b) << "(" << V3::dot(a, b) << ")" << endl;
		cout << "外積: " << a.cross(b) << "(" << V3::cross(a, b) << ")" << endl;
		cout << "切り捨て: " << a.floorf(2) << endl;
		cout << "直交座標から球座標への変換: " << a.to_spherial() << endl;
		cout << FOOTER << endl;
	}

	{
		cout << HEADER("NumPP") << endl;
		cout << "Σ[1..4]k: " << numpp::sigma(1, 4) << endl;
		cout << FOOTER << endl;
	}
}
