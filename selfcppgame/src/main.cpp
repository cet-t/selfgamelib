#include <bits/stdc++.h>

#include "trrne/trrne.h"
#include "trrne/v2.h"
#include "trrne/rnd.h"
#include "trrne/lottery.h"
#include "trrne/numpp.h"

using namespace std;
using namespace trrne;

int main()
{
	constexpr auto HEADER = [](string title)
	{
		cout << "------- " + title + " -------" << endl;
	};
	constexpr auto FOOTER = []()
	{
		cout << "--------------------\n"
			 << endl;
	};

	{
		HEADER("v2");
		V2 a(1.9f, 2.2f), b(3.8f, -1.1f), c = a + b;
		cout << "c: " << (string)c << endl;
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
		cout << "normalize: " << a.normalize().to_str() << "(" << V2::normalize(a).to_str() << ")" << endl;
		cout << "norm: " << a.magnitude() << "(" << V2::magnitude(a) << ")" << endl;
		cout << "dot: " << a.dot(b) << "(" << V2::dot(a, b) << ")" << endl;
		cout << "cross: " << a.cross(b) << "(" << V2::cross(a, b) << ")" << endl;
		cout << "floor: " << a.floorf(2).to_str() << endl;
		cout << "p2n: " << a.to_polar().to_str() << endl;
		FOOTER();
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
		HEADER("numpp");
		float a = 0.001f, b = 0.002f;
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "Σ[a..b]k: " << numpp::sigma(int(a * 1000), int(b * 1200)) << endl;
		cout << "twins: " << to_str(numpp::twins(a, b)) << endl;
		FOOTER();
	}

	{
		HEADER("rnd");
		cout << "randint: " << rnd::randint(0, 10) << endl;
		cout << "randdouble: " << rnd::randdouble(0, 10.0) << endl;
		char out[5] = {};
		rnd::randchar(out, 5);
		cout << "randchar: " << out << endl;
		FOOTER();
	}

	{
		HEADER("lottery");
		const int N = 5, L = 5;
		string rarity[N]{"UR", "SSR", "SR", "R", "C"};
		double weights[N]{0.1, 1.0, 10.0, 50.0, 100.0};
		int counters[N]{0, 0, 0, 0, 0};
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				counters[lottery::bst(weights, N)]++;
			}
		}
		double total = sum(weights, N);
		cout << total << endl;
		// for (int i = 0; i < N; ++i)
		// {
		// 	cout << rarity[i] << "("
		// 		 << numpp::round(weights[i] / total * 100, 1) << "%): "
		// 		 << counters[i] << "("
		// 		 << (counters[i] / L * 100) << "%)" << endl;
		// }
		FOOTER();
	}
}
