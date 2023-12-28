using System.Text;
using System.Security.Cryptography;
using trrne;

void println(object obj) => Console.WriteLine(obj);
double rand(double min = -10, double max = 10) => new Random().NextDouble() * (max - min) + min;

void Loop<T>(int loop, Func<T> func)
{
    for (int i = 0; i < loop; ++i)
    {
        func();
    }
}

void Space(string title, Func<object> func)
{
    string line = "------------------------------";
    println(line + " " + title + " " + line);
    println(func());
    string dst = line + line + "--";
    for (int i = 0; i < title.Length; ++i)
    {
        dst += "-";
    }
    println(dst);
}

const string N = "\n";

Space("v2", () =>
{
    string dst = "";

    V2 a = new(rand(), rand()),
        b = new(rand(), rand());
    dst += "+a          : " + (+a).Str() + N;
    dst += "-b          : " + (-b).Str() + N;
    dst += "a+b         : " + (a + b).Str() + N;
    dst += "a-b         : " + (a - b).Str() + N;
    dst += "a*b         : " + (a * b).Str() + N;
    dst += "a/b         : " + (a / b).Str() + N;
    dst += "a>b         : " + (a > b) + N;
    dst += "a>=b        : " + (a >= b) + N;
    dst += "a<b         : " + (a < b) + N;
    dst += "a<=b        : " + (a <= b) + N;
    dst += "a==b        : " + (a == b) + N;
    dst += "a!=b        : " + (a != b) + N;
    dst += "a.magnitude : " + a.Mag + N;
    dst += "b.magnitude : " + b.Mag + N;
    dst += "a.normalize : " + a.Nor.Str() + N;
    dst += "b.normalize : " + b.Nor.Str() + N;
    dst += "dot         : " + V2.Dot(a, b) + N;
    dst += "dot2        : " + V2.Dot2(a, b) + N;
    dst += "angle       : " + V2.Angle(a, b) + N;
    dst += "menseki?    : " + V2.NankanoMenseki(a, b) + N;
    return dst;
});

Space("v3", () =>
{
    string dst = "";

    V3 a = new(rand(), rand(), rand()),
        b = new(rand(), rand(), rand());
    dst += "+a          : " + (+a).Str() + N;
    dst += "-b          : " + (-b).Str() + N;
    dst += "a+b         : " + (a + b).Str() + N;
    dst += "a-b         : " + (a - b).Str() + N;
    dst += "a*b         : " + (a * b).Str() + N;
    dst += "a/b         : " + (a / b).Str() + N;
    dst += "a>b         : " + (a > b) + N;
    dst += "a>=b        : " + (a >= b) + N;
    dst += "a<b         : " + (a < b) + N;
    dst += "a<=b        : " + (a <= b) + N;
    dst += "a==b        : " + (a == b) + N;
    dst += "a!=b        : " + (a != b) + N;
    dst += "a.mag       : " + a.Mag + N;
    dst += "b.mag       : " + b.Mag + N;
    dst += "a.nor       : " + (string)a.Nor + N;
    dst += "b.nor       : " + (string)b.Nor + N;
    dst += "dot         : " + V3.Dot(a, b) + N;
    dst += "dot2        : " + V3.Dot2(a, b) + N;
    return dst;
});

Space("lottery", () =>
{
    string dst = "";

    const int L = 1000000;
    LotteryPair<string> pairs = new(
        ("大吉", 1.5),
        ("中吉", 2),
        ("吉", 3),
        ("小吉", 2.5),
        ("末吉", 1.25),
        ("凶", 0.5),
        ("大凶", 0.1)
    );
    int[] counter = new int[pairs.Len];
    Loop(L, () => counter[Lottery.Bst(pairs.Weights)]++);
    for (int i = 0; i < pairs.Len; ++i)
    {
        dst += pairs.Subjects[i] + "(" + M.Floor(pairs.Weights[i] / pairs.TotalWeights * 100, 2) + "%): ";
        dst += counter[i] + "(" + M.Floor((double)counter[i] / L * 100, 2) + "%)";
        if (i < pairs.Len - 1)
        {
            dst += N;
        }
    }
    return dst;
});

Space("rsa", () =>
{
    const string SRC = "karachan";
    string dst = "src: " + SRC + N;

    dst += "=========dynamic=========" + N;
    {
        MyRSA mrsa = new(RSAEncryptionPadding.Pkcs1);
        byte[] en = mrsa.En(SRC);
        dst += "en: {" + Encoding.UTF8.GetString(en) + "}" + N + N;
        dst += "de: {" + mrsa.De2Str(en) + "}" + N;
    }

    dst += "=========static=========" + N;
    {
        byte[] en = MyRSA.En(SRC);
        dst += "en: {" + Encoding.UTF8.GetString(en) + "}" + N + N;
        dst += "de: {" + MyRSA.De2Str(en) + "}" + N;
    }

    return dst;
});

Space("math", () =>
{
    string dst = "";

    const int L = 20; // 20以上は無理
    for (int i = 1; i <= L; ++i)
    {
        dst += i + "!: " + M.Factorial(i);
        if (i < L)
        {
            dst += N;
        }
    }
    // dst += N + "max: " + ulong.MaxValue;
    return dst;
});
