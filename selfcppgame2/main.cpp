#include <iostream>
#include <string.h>

#include "trrne.h"
#include "v2.h"
//#include "v3.h"
//#include "crypto22.h"
#include "rnd.h"

using namespace std;
using namespace trrne;

int main() {
	constexpr auto HEADER = [](string title) {
		return "------- " + title + " -------";
	};
	const auto FOOTER = "--------------------\n";

	{
		cout << HEADER("Vector2D") << endl;
		V2 a(1.9f, 2.2f), b(3.8f, -1.1f), c = a + b;
		cout << "c: " << c.to_str() << endl;
		cout << "+a: " << (+a).to_str() << endl;
		cout << "-b: " << (-b).to_str() << endl;
		cout << "+: " << (a + b).to_str() << endl;
		cout << "-: " << (a - b).to_str() << endl;
		cout << "*: " << (a * b).to_str() << endl;
		cout << "/: " << (a / b).to_str() << endl;
		cout << "+=: " << (a += b).to_str() << endl;
		cout << "-=: " << (a -= b).to_str() << endl;
		cout << "*=: " << (a *= b).to_str() << endl;
		cout << "/=: " << (a /= b).to_str() << endl;
		cout << "<: " << (a < b) << endl;
		cout << "<=: " << (a <= b) << endl;
		cout << ">: " << (a > b) << endl;
		cout << ">=: " << (a <= b) << endl;
		cout << "==: " << (a == b) << endl;
		cout << "!=: " << (a != b) << endl;
		cout << "正規化: " << a.normalize().to_str() << "(" << V2::normalize(a).to_str() << ")" << endl;
		cout << "ノルム: " << a.magnitude() << "(" << V2::magnitude(a) << ")" << endl;
		cout << "内積: " << a.dot(b) << "(" << V2::dot(a, b) << ")" << endl;
		cout << "外積: " << a.cross(b) << "(" << V2::cross(a, b) << ")" << endl;
		cout << "切り捨て: " << a.floorf(2).to_str() << endl;
		cout << "極座標からの変換: " << a.to_polar().to_str() << endl;
		cout << FOOTER << endl;
	}

	//{
	//	cout << HEADER("CRYPTO") << endl;
	//	const auto src = "aiueokakikukeko";
	//	auto crypto = crypto22();
	//	string e = crypto.en(src), d = crypto.de(e);
	//	cout << "src: " << src << endl;
	//	cout << "encrypt: " << e << endl;
	//	cout << "decrypt: " << d << endl;
	//	cout << FOOTER << endl;
	//}

	//{
	//	cout << HEADER("Vector3D") << endl;
	//	V3 a(1, 2, 4), b(-4, 3, -1);
	//	cout << "a: " << a << endl;
	//	cout << "b: " << b << endl;
	//	cout << "+: " << +a << "(sign)" << endl;
	//	cout << "-: " << -b << "(sign)" << endl;
	//	cout << "+: " << a + b << endl;
	//	cout << "-: " << a - b << endl;
	//	cout << "*: " << a * b << endl;
	//	cout << "/: " << a / b << endl;
	//	cout << "+=: " << (a += b) << endl;
	//	cout << "-=: " << (a -= b) << endl;
	//	cout << "*=: " << (a *= b) << endl;
	//	cout << "/=: " << (a /= b) << endl;
	//	cout << "==: " << (a == b) << endl;
	//	cout << "!=: " << (a != b) << endl;
	//	cout << "正規化: " << a.normalize() << "(" << V3::normalize(a) << ")" << endl;
	//	cout << "ノルム: " << a.magnitude() << "(" << V3::magnitude(a) << ")" << endl;
	//	cout << "内積: " << a.dot(b) << "(" << V3::dot(a, b) << ")" << endl;
	//	cout << "外積: " << a.cross(b) << "(" << V3::cross(a, b) << ")" << endl;
	//	cout << "切り捨て: " << a.floorf(2) << endl;
	//	cout << "直交座標から球座標への変換: " << a.to_spherial() << endl;
	//	cout << FOOTER << endl;
	//}

	{
		cout << HEADER("numpp") << endl;
		float a = 0.001f, b = 0.002f;
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "Σ[a..b]k: " << numpp::sigma(int(a * 1000), int(b * 1200)) << endl;
		cout << "twins: " << to_str(numpp::twins(a, b)) << endl;
		cout << FOOTER << endl;
	}

	{
		cout << HEADER("rnd") << endl;
		cout << "randint: " << rnd::randint(0, 10) << endl;
		cout << "randfloat: " << rnd::randfloat(0, 10.f) << endl;
		char out[5] = {};
		rnd::randchar(out, 5);
		cout << "randchar: " << out << endl;
		cout << FOOTER << endl;
	}
}
