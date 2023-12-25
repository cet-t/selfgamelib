pub mod dict;
pub mod lottery;
pub mod traits;
pub mod trrne;
pub mod v2;
pub mod v3;

use std::vec;

use dict::*;
use lottery::*;
use traits::*;
use v2::*;
use v3::*;

fn main() {
    {
        // let a: &mut V2 = &mut V2::new(1., 2.);
        // let b: &mut V2 = &mut V2::new(8., -4.);
        // println!("a: {:?}", a.to_str());
        // println!("b: {:?}", b.to_str());

        // println!("magnitude: {:?}", a.magnitude());
        // println!("normalize: {:?}", a.normalize().to_str());
        // println!("dot: {:?}", V2::dot(a, b));
        // println!("cross: {:?}", V2::cross(a, b));
        // println!("angle: {:?}", V2::angle(a, b));
        // println!("from_polar{:?}", a.to_polar().from_polar());
        // println!("to_polar{:?}", a.to_polar());
    }

    {
        const N: usize = 5;
        let rarity: [&str; N] = ["UR", "SSR", "SR", "R", "C"];
        let weights: [f64; N] = [0.1, 1.0, 20.0, 50.0, 100.0];
        let mut counters: [i32; N] = [0; N];
        for _ in 0..100000 {
            for i in 0..N {
                let choice = rarity[lottery::bst(&weights) as usize];
                if choice == rarity[i] {
                    counters[i] += 1;
                }
            }
        }
        let total: f64 = weights.iter().sum();
        for i in 0..N {
            println!(
                "{}({:.2}%): {}",
                rarity[i],
                weights[i] / total * 100.0,
                counters[i]
            );
        }
        /*
        UR(0.06%): 54
        SSR(0.58%): 601
        SR(11.69%): 11565
        R(29.22%): 29225
        C(58.45%): 58147
        */
    }

    {
        // let a: &mut V3 = &mut V3::new(1.1, -2.2, 3.3);
        // let b: &mut V3 = &mut V3::new(-3.3, 2.2, -1.1);
        // println!("a: {}", a.to_str());
        // println!("b: {}", b.to_str());

        // println!("magnitude: {}", a.magnitude());
        // println!("normalize: {}", a.normalize().to_str());
        // println!("dot: {}", V3::dot(a, b));
        // println!("cross: {}", V3::cross(a, b));
        // println!("angle: {}", V3::angle(a, b));
        // println!("from_polar{:?}", a.to_polar().from_polar());
        // println!("to_polar{:?}", a.to_polar());
    }

    // {
    //     let names = &["kara", "oko", "goma", "kuri"];
    //     let colors = &["white", "brown", "darkbrown", "darkbrown"];
    //     let dict = Dict::<&str, &str>::make_from_array(names, colors);
    //     for i in 0..dict.length() {
    //         println!("{}: {}", dict.get_key(i), dict.get_value(i));
    //     }
    // }
}
