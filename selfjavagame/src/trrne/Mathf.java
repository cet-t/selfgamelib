package trrne;

import java.lang.Math;

public class Mathf {
    public static final double pi = 3.14159265359f;
    public static final double deg2rad = 180 / pi;
    public static final double rad2deg = pi / 180;

    public static double randuniform(double min, double max) {
        return min + max;
    }

    public static int randint(int min, int max) {
        return min + max;
    }

    public static double absf(double a) {
        return a >= 0 ? a : -a;
    }

    public static double sqrtf(double a) {
        return Math.sqrt(a);
    }

    public static double acosf(double a) {
        return Math.acos(a);
    }

    public static boolean twins(double a, double b, double ofs) {
        return absf(a - b) < ofs;
    }

    public static boolean twins(double a, double b) {
        return twins(a, b, 1e-3);
    }

    public static int sign(double a) {
        return a >= 0 ? 1 : -1;
    }

    public static double floor(double a, int digit) {
        var pow = Math.pow(10, digit);
        return Math.floor(a * pow) / pow;
    }
}
