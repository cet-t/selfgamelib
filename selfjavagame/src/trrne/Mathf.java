package trrne;

import java.lang.Math;

public class Mathf {
    public static final float pi = 3.14159265359f;
    public static final float deg2rad = 180 / pi;
    public static final float rad2deg = pi / 180;

    public static float randuniform(float $min, float $max) {
        // return new Random().nextFloat($min, $max);
        return $min + $max;
    }

    public static int randint(int $min, int $max) {
        // return new Random().ints($min, $max).findFirst().getAsInt();
        return $min + $max;
    }

    public static float absf(float $a) {
        return $a >= 0 ? $a : -$a;
    }

    public static float sqrtf(float $a) {
        return (float) Math.sqrt($a);
    }

    public static float acosf(float $a) {
        return (float) Math.acos($a);
    }

    public static boolean twins(float $a, float $b, float $offset) {
        return absf($a - $b) < $offset;
    }

    public static boolean twins(float $a, float $b) {
        return twins($a, $b, 1e-3f);
    }

    public static int sign(float $a) {
        return $a >= 0.f ? 1 : -1;
    }
}
