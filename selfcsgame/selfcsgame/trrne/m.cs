namespace trrne;

public static class M
{
    public const double RadToDeg = 180 / Math.PI;
    public const double DegToRad = Math.PI / 180;

    public static double ToDeg(double rad) => rad * RadToDeg;
    public static double ToRad(double deg) => deg * DegToRad;

    public static double Floor(double n, int digit)
    {
        var e = Math.Pow(10, digit);
        return Math.Floor(e * n) / e;
    }

    public static ulong Factorial(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        else if (n == 1 || n == 2)
        {
            return (ulong)n;
        }

        ulong dst = 1;
        for (uint i = 1; i <= n; ++i)
        {
            dst *= i;
        }
        return dst;
    }

    public static ulong Permutation(int n, int r) => Factorial(n) / Factorial(n - r);
    public static ulong? Combination(int n, int r) => (r >= 0 && n >= r) ? null : Factorial(n) / (Factorial(r) * Factorial(n - r));
}