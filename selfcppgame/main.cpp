#include <iostream>
#include <map>
#include <random>
#include <ctime>
// #include <string>
#include <vector>
#include <mem.h>
#include <math.h>
#include <cstring>

#include "src/trrne/trrne.hpp"
#include "src/trrne/v2.hpp"
#include "src/trrne/mathf.hpp"
#include "src/trrne/lottery.hpp"

using namespace trrne;
using namespace std;
using namespace chrono;

struct ahokaina
{
public:
    char name[32];
    ahokaina(char *$name)
    {
        strncpy(name, $name, length(name));
        name[length(name)] = '\0';
    }
};

int main()
{
    // V2 a(2, 4), b(8, 15),
    //     v2s[] = {a + b, a - b, a * b, a / b};
    // cout << length(v2s) << endl;
    // for (auto &v : v2s)
    //     cout << v.to_string(1) << endl;
    // cout << "length: " << length(v2s) << endl;
    // cout << "-------------" << endl;
    // cout << V2::angle(a, b) << endl;

    // cout << "a:" << a << endl
    //      << "b:" << b << endl
    //      << "+: " << v2s[0] << endl
    //      << "-: " << v2s[1] << endl
    //      << "*: " << v2s[2] << endl
    //      << "/: " << v2s[3] << endl;

    // cout << mathf::floor(0.1234567890, 2) << endl;

    // vector<float> weights = {60, 30, 10};
    // float weights1[] = {100, 40, 5};
    // string rares[3]{"R", "SR", "SSR"};
    // for (int i = 0; i < 8; i++)
    {
        // cout << rares[lottery::binary_search_tree(weights1, length(weights1))] << endl;
        // cout << lottery::binary_search_tree(weights, weights.size()) << endl;

        // cout << rnd::randuniform(0, 10) << endl;
        // cout << rnd::randint(0, 10) << endl;

        const int length = 32;
        char _out[length] = {};
        rnd::randchar(_out, length);
        cout << "out: " << _out << endl;
    }

    // auto *name = new char[5];
    // strncpy(name, "kara\0", 5);
    // ahokaina t(name);
    // // ahokaina t("kara"); // よくない
    // cout << t.name << endl;
    // delete[] name;

    return 0;
}
