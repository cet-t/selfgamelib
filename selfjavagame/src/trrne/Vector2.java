﻿package trrne;

public class Vector2 {
    public static final Vector2 X = new Vector2(1, 0);
    public static final Vector2 Y = new Vector2(0, 1);
    public static final Vector2 Zero = new Vector2(0, 0);
    public static final Vector2 One = new Vector2(1, 1);

    public double x, y;

    public Vector2() {
        x = 0;
        y = 0;
    }

    public Vector2(double $x, double $y) {
        x = $x;
        y = $y;
    }

    public Vector2 add(final Vector2 $a) {
        return new Vector2(x + $a.x, y + $a.y);
    }

    public Vector2 sub(final Vector2 $a) {
        return new Vector2(x - $a.x, y - $a.y);
    }

    public Vector2 div(final double $a) {
        return new Vector2(x / $a, y / $a);
    }

    public Vector2 mul(final Vector2 $a) {
        return new Vector2(x * $a.x, y * $a.y);
    }

    public Vector2 mul(final double $a) {
        return new Vector2(x * $a, y * $a);
    }

    public static double cross(final Vector2 $a, final Vector2 $b) {
        return $a.x * $b.y - $a.y * $b.x;
    }

    public static double dot(final Vector2 $a, final Vector2 $b) {
        return $a.x * $b.x + $a.y * $b.y;
    }

    public double magnitude() {
        return Mathf.sqrtf(x * x + y * y);
    }

    public static double magnitude(final Vector2 $a) {
        return $a.magnitude();
    }

    public Vector2 normalize() {
        return div(magnitude());
    }

    public static Vector2 normalize(final Vector2 $a) {
        return $a.normalize();
    }

    public static double distance(final Vector2 $a, final Vector2 $b) {
        return magnitude($a.sub($b));
    }

    public static double angle(final Vector2 $a, final Vector2 $b) {
        final double a = $a.magnitude(), b = $b.magnitude();
        if (Math.abs(a) <= 1e-45 || Math.abs(b) <= 1e-45) {
            return 0;
        }
        return Mathf.acosf(dot($a, $b) / a / b) * Mathf.rad2deg;
    }

    public static boolean twins(final Vector2 $v1, final Vector2 $v2, final double tolerance) {
        return Math.abs($v1.x - $v2.x) < tolerance && Math.abs($v1.y - $v2.y) < tolerance;
    }

    public static boolean twins(final Vector2 $v1, final Vector2 $v2) {
        return twins($v1, $v2, 1e-3f);
    }

    public String toString() {
        return "(" + x + "," + y + ")";
    }
}
