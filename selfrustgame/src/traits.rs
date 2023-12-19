#[allow(non_camel_case_types)]
pub trait f32e {
    fn pif() -> f32;
    fn to_deg() -> f32;
    fn to_rad() -> f32;
    fn absf(a: f32) -> f32;
    fn sinf(a: f32) -> f32;
    fn asinf(a: f32) -> f32;
    fn cosf(a: f32) -> f32;
    fn acosf(a: f32) -> f32;
    fn tanf(a: f32) -> f32;
    fn atanf(a: f32) -> f32;
    fn sqrtf(a: f32) -> f32;
}

impl f32e for f32 {
    fn pif() -> f32 {
        3.1415926535
    }

    fn to_deg() -> f32 {
        180. / f32::pif()
    }

    fn to_rad() -> f32 {
        f32::pif() / 180.
    }

    fn absf(a: f32) -> f32 {
        a.abs()
    }

    fn sinf(a: f32) -> f32 {
        a.sin()
    }

    fn asinf(a: f32) -> f32 {
        a.asin()
    }

    fn cosf(a: f32) -> f32 {
        a.cos()
    }

    fn acosf(a: f32) -> f32 {
        a.acos()
    }

    fn tanf(a: f32) -> f32 {
        a.tan()
    }

    fn atanf(a: f32) -> f32 {
        a.atan()
    }

    fn sqrtf(a: f32) -> f32 {
        a.sqrt()
    }
}
