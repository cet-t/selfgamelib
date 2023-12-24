#[allow(non_camel_case_types)]
pub trait fe<f> {
    fn pi() -> f;
    fn to_deg() -> f;
    fn to_rad() -> f;
}

impl fe<f32> for f32 {
    fn pi() -> f32 {
        3.1415926535
    }

    fn to_deg() -> f32 {
        180. / f32::pi()
    }

    fn to_rad() -> f32 {
        f32::pi() / 180.
    }
}

impl fe<f64> for f64 {
    fn pi() -> f64 {
        3.14159265358979323846264338327950288
    }

    fn to_deg() -> f64 {
        180. / f64::pi()
    }

    fn to_rad() -> f64 {
        f64::pi() / 180.
    }
}

pub trait ArrayExt<T> {
    fn sum(array: &[T]) -> T;
}

impl ArrayExt<f32> for [f32] {
    fn sum(array: &[f32]) -> f32 {
        let mut dst: f32 = 0.;
        for i in array {
            dst += i;
        }
        dst
    }
}

impl ArrayExt<i32> for [i32] {
    fn sum(array: &[i32]) -> i32 {
        let mut dst: i32 = 0;
        for i in array {
            dst += i;
        }
        dst
    }
}
