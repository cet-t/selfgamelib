namespace trrne;

public class V2(double x, double y)
{
    public V2() : this(0, 0) { }
    public V2(V2 a) : this(a.x, a.y) { }

    public double x = x, y = y;

    public double Mag => Math.Sqrt(x * x + y * y);
    public V2 Nor => new(x / Mag, y / Mag);

    public V2 Floor(int digit) => new(M.Floor(x, digit), M.Floor(y, digit));

    public static double Dot(V2 a, V2 b) => a.x * b.x + a.y * b.y;
    public static double Angle(V2 a, V2 b) => M.ToDeg(Math.Acos(Dot(a, b) / a.Mag / b.Mag));

    public static double Dot2(V2 a, V2 b) => a.Mag * b.Mag * Math.Cos(Angle(a, b));

    public V2 Polar => new(x * Math.Cos(y), x * Math.Sin(y));

    public static double NankanoMenseki(V2 a, V2 b)
    => Math.Sqrt((a.Mag * a.Mag * b.Mag * b.Mag) - (Dot(a, b) * Dot(a, b))) / 2;

    #region Operators

    public static V2 operator +(V2 a) => new(+a.x, +a.y);
    public static V2 operator -(V2 a) => new(-a.x, -a.y);

    public static V2 operator +(V2 a, V2 b) => new(a.x + b.x, a.y + b.y);
    public static V2 operator +(V2 a, double b) => new(a.x + b, a.y + b);
    public static V2 operator +(double a, V2 b) => new(a + b.x, a + b.y);

    public static V2 operator -(V2 a, V2 b) => new(a.x - b.x, a.y - b.y);
    public static V2 operator -(V2 a, double b) => new(a.x - b, a.y - b);
    public static V2 operator -(double a, V2 b) => new(a - b.x, a - b.y);

    public static V2 operator *(V2 a, V2 b) => new(a.x * b.x, a.y * b.y);
    public static V2 operator *(V2 a, double b) => new(a.x * b, a.y * b);
    public static V2 operator *(double a, V2 b) => new(a * b.x, a * b.y);

    public static V2 operator /(V2 a, V2 b) => new(a.x / b.x, a.y / b.y);
    public static V2 operator /(V2 a, double b) => new(a.x / b, a.y / b);
    public static V2 operator /(double a, V2 b) => new(a / b.x, a / b.y);

    public static V2 operator %(V2 a, V2 b) => new(a.x % b.x, a.y % b.y);
    public static V2 operator %(V2 a, double b) => new(a.x % b, a.y % b);
    public static V2 operator %(double a, V2 b) => new(a % b.x, a % b.y);

    public static bool operator ==(V2 a, V2 b) => a.x == b.x && a.y == b.y;
    public static bool operator !=(V2 a, V2 b) => a.x != b.x && a.y != b.y;

    public static bool operator <(V2 a, V2 b) => a.x < b.x && a.y < b.y;
    public static bool operator >(V2 a, V2 b) => a.x > b.x && a.y > b.y;
    public static bool operator <=(V2 a, V2 b) => a.x <= b.x && a.y <= b.y;
    public static bool operator >=(V2 a, V2 b) => a.x >= b.x && a.y >= b.y;

    public static explicit operator V3(V2 a) => new(a.x, a.y, 0);
    public static explicit operator double(V2 a) => a.Mag;
    public static explicit operator string(V2 a) => $"({a.x},{a.y})";
    public string Str() => (string)this;

    #endregion

    public override bool Equals(object? obj) => base.Equals(obj);
    public override int GetHashCode() => base.GetHashCode();
}

public sealed class V3(double x, double y, double z)
{
    public V3() : this(0, 0, 0) { }
    public V3(V3 a) : this(a.x, a.y, a.z) { }

    public double x = x, y = y, z = z;

    public double Mag => Math.Sqrt(x * x + y * y + z * z);
    public V3 Nor => new(x / Mag, y / Mag, z / Mag);

    public V3 Floor(int digit) => new(M.Floor(x, digit), M.Floor(y, digit), M.Floor(z, digit));

    public static double Dot(V3 a, V3 b) => a.x * b.x + a.y * b.y + a.z * b.z;
    public static double Cross(V3 a, V3 b) => a.y * b.x - b.z * a.x - a.y * b.z;
    public static double Angle(V3 a, V3 b) => M.ToDeg(Math.Acos(Dot(a, b) / a.Mag / b.Mag));
    public static double Dot2(V3 a, V3 b) => a.Mag * b.Mag * Math.Cos(Angle(a, b));

    public static V3 operator +(V3 a) => new(+a.x, +a.y, +a.z);
    public static V3 operator -(V3 a) => new(-a.x, -a.y, -a.z);

    public static V3 operator +(V3 a, V3 b) => new(a.x + b.x, a.y + b.y, a.z + b.z);
    public static V3 operator +(V3 a, double b) => new(a.x + b, a.y + b, a.z + b);
    public static V3 operator +(double a, V3 b) => new(a + b.x, a + b.y, a + b.z);

    public static V3 operator -(V3 a, V3 b) => new(a.x - b.x, a.y - b.y, a.z - b.z);
    public static V3 operator -(V3 a, double b) => new(a.x - b, a.y - b, a.z - b);
    public static V3 operator -(double a, V3 b) => new(a - b.x, a - b.y, a - b.z);

    public static V3 operator *(V3 a, V3 b) => new(a.x * b.x, a.y * b.y, a.z * b.z);
    public static V3 operator *(V3 a, double b) => new(a.x * b, a.y * b, a.z * b);
    public static V3 operator *(double a, V3 b) => new(a * b.x, a * b.y, a * b.z);

    public static V3 operator /(V3 a, V3 b) => new(a.x / b.x, a.y / b.y, a.z / b.z);
    public static V3 operator /(V3 a, double b) => new(a.x / b, a.y / b, a.z / b);
    public static V3 operator /(double a, V3 b) => new(a / b.x, a / b.y, a / b.z);

    public static V3 operator %(V3 a, V3 b) => new(a.x % b.x, a.y % b.y, a.z % b.z);
    public static V3 operator %(V3 a, double b) => new(a.x % b, a.y % b, a.z % b);
    public static V3 operator %(double a, V3 b) => new(a % b.x, a % b.y, a % b.z);

    public static bool operator ==(V3 a, V3 b) => a.x == b.x && a.y == b.y && a.z == b.z;
    public static bool operator !=(V3 a, V3 b) => !(a == b);

    public static bool operator <(V3 a, V3 b) => a.x < b.x && a.y < b.y;
    public static bool operator >(V3 a, V3 b) => a.x > b.x && a.y > b.y;
    public static bool operator <=(V3 a, V3 b) => a.x <= b.x && a.y <= b.y;
    public static bool operator >=(V3 a, V3 b) => a.x >= b.x && a.y >= b.y;

    public static explicit operator V2(V3 a) => new(a.x, a.y);
    public static explicit operator double(V3 a) => a.Mag;
    public static explicit operator string(V3 a) => $"({a.x},{a.y},{a.z})";
    public string Str() => (string)this;

    public override bool Equals(object? obj) => base.Equals(obj);
    public override int GetHashCode() => base.GetHashCode();
}