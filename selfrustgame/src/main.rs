pub mod lottery;
pub mod traits;
pub mod v2;
use lottery::*;
use v2::*;

fn main() {
    let a = &mut V2::new(1., 2.);
    let b = &mut V2::new(8., -4.);
    println!("a: {:?}", a.to_str());
    println!("b: {:?}", b.to_str());

    println!("magnitude: {:?}", a.magnitude());
    println!("normalize: {:?}", a.normalize().to_str());
    println!("dot: {:?}", V2::dot(a, b));
    println!("cross: {:?}", V2::cross(a, b));
    println!("angle: {:?}", V2::angle(a, b));
    println!("from_polar{:?}", a.to_polar().from_polar());
    println!("to_polar{:?}", a.to_polar());

    let weights: &[f32] = &[0.1, 0.3, 1.2, 4.5, 100.];
    for i in 0..100 {
        println!("bst: {:?}", lottery::bst(&weights));
    }
}
