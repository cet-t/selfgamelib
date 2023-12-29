#include <bits/stdc++.h>

#include "trrne/trrne.h"
#include "trrne/v2.h"
#include "trrne/rnd.h"
#include "trrne/lottery.h"
#include "trrne/numpp.h"

using namespace std;
using namespace trrne;

constexpr char N = '\n';

void space(string name, char design, string dst)
{
    string line;
    for (int i = 0; i < 32; ++i)
    {
        line += design;
    }
    cout << line << "|| " << name << " ||" << line << endl;
    cout << dst << endl;
    string underline = line + line;
    for (int i = 0; i < name.length() + 6; ++i)
    {
        underline += design;
    }
    cout << underline << endl;
}

int main()
{
    space("numpp", '-', []()
          {
        stringstream ss;
        double a = 0.001, b = 0.002;
        ss << "a            : " << a << endl;
        ss << "b            : " << b << endl;
        ss << "E[a..b]k     : " << numpp::sigma(int(a * 1000), int(b * 1200)) << endl;
        ss << "twins(a,b)   : " << str(numpp::twins(a, b)) << endl;
        return ss.str(); }());

    space("rand", '-', []()
          {
        stringstream ss;
        ss << "int	: " << rnd::randint(0, 10) << endl;
        ss << "double	: " << rnd::randdouble(0.0, 10.0) << endl;
        char out[5]{};
        rnd::randchar(out, 5);
        ss << "char	: " << out;
        return ss.str(); }());

    space("v2", '-', []()
          {
        stringstream ss;
    	V2 a(rnd::randdouble(-10, 10),rnd::randdouble(-10, 10)), 
            b(rnd::randdouble(-10, 10),rnd::randdouble(-10, 10)),
            c = a + b;
        ss << "+a       : " << (+a).str() << N;
        ss << "-b       : " << (-b).str() << N;
        ss << "c        : " << c.str() << N;
        ss << "a+b      : " << (a + b).str() << N;
        ss << "a-b      : " << (a - b).str() << N;
        ss << "a*b      : " << (a * b).str() << N;
        ss << "a/b      : " << (a / b).str() << N;
        ss << "a+=b     : " << (a += b).str() << N;
        ss << "a-=b     : " << (a -= b).str() << N;
        ss << "a*=b     : " << (a *= b).str() << N;
        ss << "a/=b     : " << (a /= b).str() << N;
        ss << "a<b      : " << str(a < b) << N;
        ss << "a<=b     : " << str(a <= b) << N;
        ss << "a>b      : " << str(a > b) << N;
        ss << "a>=b     : " << str(a <= b) << N;
        ss << "a==b     : " << str(a == b) << N;
        ss << "a!=b     : " << str(a != b) << N;
        ss << "nor      : " << a.nor().str() << "(" << V2::nor(a).str() << ")" << N;
        ss << "norm     : " << a.mag() << "(" << V2::mag(a) << ")" << N;
        ss << "dot      : " << V2::dot(a, b) << N;
        ss << "floor    : " << a.floor(2).str() << N;
        ss << "p2n      : " << a.to_polar().str();
        return ss.str(); }());
}
