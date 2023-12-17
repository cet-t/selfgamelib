use crate::traits::*;
use std::ops::*;

#[derive(Debug, Clone, Copy)]
pub struct V2 {
    pub x: f32,
    pub y: f32,
}

pub trait V2e {
    fn new(x: f32, y: f32) -> V2;
    fn to_str(&self) -> String;

    fn magnitude(&self) -> f32;
    fn normalize(&self) -> V2;
    fn distance(a: &mut V2, b: &mut V2) -> f32;
    fn dot(a: &mut V2, b: &mut V2) -> f32;
    fn cross(a: &mut V2, b: &mut V2) -> f32;
    fn angle(a: &mut V2, b: &mut V2) -> f32;

    fn from_polar(&self) -> V2;
    fn to_polar(&self) -> V2;
}

impl V2e for V2 {
    fn new(x: f32, y: f32) -> V2 {
        V2 { x, y }
    }

    fn to_str(&self) -> String {
        format!("({}, {})", self.x, self.y)
    }

    fn magnitude(&self) -> f32 {
        f32::sqrtf(self.x * self.x + self.y * self.y)
    }

    fn normalize(&self) -> V2 {
        V2::new(self.x / self.magnitude(), self.y / self.magnitude())
    }

    fn distance(a: &mut V2, b: &mut V2) -> f32 {
        (*a - *b).magnitude()
    }

    fn dot(a: &mut V2, b: &mut V2) -> f32 {
        a.x * b.x + a.y * b.y
    }

    fn cross(a: &mut V2, b: &mut V2) -> f32 {
        a.x * b.y - a.y * b.x
    }

    fn angle(a: &mut V2, b: &mut V2) -> f32 {
        let (lal, lbl) = (a.magnitude(), b.magnitude());
        if f32::absf(lal + lbl) < f32::EPSILON {
            return 0.;
        }
        f32::acosf(V2::dot(a, b) / lal / lbl) * f32::to_deg()
    }

    fn from_polar(&self) -> V2 {
        V2::new(self.x * f32::cosf(self.y), self.x * f32::sinf(self.y))
    }

    fn to_polar(&self) -> V2 {
        V2::new(
            f32::sqrtf(self.x * self.x + self.y * self.y),
            f32::atanf(self.y / self.x),
        )
    }
}

impl Add for V2 {
    type Output = V2;
    fn add(self, rhs: Self) -> Self::Output {
        V2::new(self.x + rhs.x, self.y + rhs.y)
    }
}

impl AddAssign for V2 {
    fn add_assign(&mut self, rhs: Self) {
        self.x += rhs.x;
        self.y += rhs.y;
    }
}

impl Sub for V2 {
    type Output = V2;
    fn sub(self, rhs: Self) -> Self::Output {
        V2::new(self.x - rhs.x, self.y - rhs.y)
    }
}

impl SubAssign for V2 {
    fn sub_assign(&mut self, rhs: Self) {
        self.x -= rhs.x;
        self.y -= rhs.y;
    }
}

impl Mul for V2 {
    type Output = V2;
    fn mul(self, rhs: Self) -> Self::Output {
        V2::new(self.x * rhs.x, self.y * rhs.y)
    }
}

impl MulAssign for V2 {
    fn mul_assign(&mut self, rhs: Self) {
        self.x *= rhs.x;
        self.y *= rhs.y;
    }
}

impl Div for V2 {
    type Output = V2;
    fn div(self, rhs: Self) -> Self::Output {
        V2::new(self.x / rhs.x, self.y / rhs.y)
    }
}

impl DivAssign for V2 {
    fn div_assign(&mut self, rhs: Self) {
        self.x /= rhs.x;
        self.y /= rhs.y;
    }
}
