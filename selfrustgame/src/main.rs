pub mod dict;
pub mod lottery;
pub mod traits;
pub mod v2;

use dict::*;
use lottery::*;
use v2::*;

fn main() {
    // let (a, b) = (&mut V2::new(1., 2.), &mut V2::new(8., -4.));
    // println!("a: {:?}", a.to_str());
    // println!("b: {:?}", b.to_str());

    // println!("magnitude: {:?}", a.magnitude());
    // println!("normalize: {:?}", a.normalize().to_str());
    // println!("dot: {:?}", V2::dot(a, b));
    // println!("cross: {:?}", V2::cross(a, b));
    // println!("angle: {:?}", V2::angle(a, b));
    // println!("from_polar{:?}", a.to_polar().from_polar());
    // println!("to_polar{:?}", a.to_polar());

    const N: usize = 5;
    let weights: &[f32; N] = &[0.1, 0.3, 1.2, 4.5, 100.];
    let items: &[&str; N] = &[&"1", &"2", &"3", &"4", &"5"];
    // let mut pair = LotteryPair::<&str, N>::new(&items, &weights);
    for _ in 0..100 {
        // println!("bst: {:?}", lottery::bst(&weights));
        println!("bst: {:?}", lottery::weighted(items, weights));
    }
}
