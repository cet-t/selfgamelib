use std::ops::{Add, Div, Mul, Sub};

#[derive(Debug, Clone, Copy)]
pub struct V3 {
    pub x: f64,
    pub y: f64,
    pub z: f64,
}

pub trait V3e {
    fn new(x: f64, y: f64, z: f64) -> V3;
    fn to_str(&self) -> String;
    fn magnitude(&self) -> f64;
    fn normalize(&self) -> V3;
    fn distance(a: &mut V3, b: &mut V3) -> f64;
    fn dot(a: &mut V3, b: &mut V3) -> f64;
    fn cross(a: &mut V3, b: &mut V3) -> f64;
    fn angle(a: &mut V3, b: &mut V3) -> f64;
    fn from_polar(&self) -> V3;
    fn to_polar(&self) -> V3;
}

impl Default for V3 {
    fn default() -> Self {
        Self {
            x: Default::default(),
            y: Default::default(),
            z: Default::default(),
        }
    }
}

impl V3e for V3 {
    fn new(x: f64, y: f64, z: f64) -> V3 {
        V3 { x, y, z }
    }

    fn to_str(&self) -> String {
        format!("({}, {}, {})", self.x, self.y, self.z)
    }

    fn magnitude(&self) -> f64 {
        (self.x * self.x + self.y * self.y + self.z * self.z).sqrt()
    }

    fn normalize(&self) -> V3 {
        let m: f64 = self.magnitude();
        V3 {
            x: self.x / m,
            y: self.y / m,
            z: self.z / m,
        }
    }

    fn distance(a: &mut V3, b: &mut V3) -> f64 {
        a.magnitude() - b.magnitude()
    }

    fn dot(a: &mut V3, b: &mut V3) -> f64 {
        a.x * b.x + a.y * b.y + a.z * b.z
    }

    fn cross(a: &mut V3, b: &mut V3) -> f64 {
        a.magnitude() * b.magnitude() * V3::angle(a, b).sin()
    }

    fn angle(a: &mut V3, b: &mut V3) -> f64 {
        let (lal, lbl) = (a.magnitude(), b.magnitude());
        if (lal + lbl).abs() < 1e-44 {
            return 0.0;
        }
        V3::dot(a, b) / lal / lbl
    }

    fn from_polar(&self) -> V3 {
        todo!()
    }

    fn to_polar(&self) -> V3 {
        todo!()
    }
}

impl Add for V3 {
    type Output = V3;
    fn add(self, rhs: Self) -> Self::Output {
        V3 {
            x: self.x + rhs.x,
            y: self.y + rhs.y,
            z: self.z + rhs.z,
        }
    }
}

impl Sub for V3 {
    type Output = V3;
    fn sub(self, rhs: Self) -> Self::Output {
        V3 {
            x: self.x - rhs.x,
            y: self.y - rhs.y,
            z: self.z - rhs.z,
        }
    }
}

impl Mul for V3 {
    type Output = V3;
    fn mul(self, rhs: Self) -> Self::Output {
        V3 {
            x: self.x * rhs.x,
            y: self.y * rhs.y,
            z: self.z * rhs.z,
        }
    }
}

impl Div for V3 {
    type Output = V3;
    fn div(self, rhs: Self) -> Self::Output {
        V3 {
            x: self.x / rhs.x,
            y: self.y / rhs.y,
            z: self.z / rhs.z,
        }
    }
}
