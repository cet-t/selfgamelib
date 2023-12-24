pub mod dict;
pub mod lottery;
pub mod traits;
pub mod trrne;
pub mod v2;
pub mod v3;

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

    // const L: usize = 1000;
    // const N: usize = 5;
    // let weights: &[f32; N] = &[7.5, 4.5, 1.2, 0.3, 0.1];
    // let items: &[&str; N] = &[&"C  ", &"R  ", &"SR ", &"SSR", &"L  "];
    // let counter: &mut [i32; N] = &mut [0, 0, 0, 0, 0];
    // for i in 0..L as usize {
    //     let choice = lottery::weighted(items, weights);
    //     if choice == items[i % N] {
    //         counter[i % N] += 1;
    //     }
    // }
    // println!("LOOP: {:?}", L);
    // for i in 0..N {
    //     println!(
    //         "{}({}%): {}",
    //         items[i],
    //         weights[i] / L as f32 * 100.,
    //         counter[i]
    //     );
    // }

    {
        let a: &mut V3 = &mut V3::new(1.1, -2.2, 3.3);
        let b: &mut V3 = &mut V3::new(-3.3, 2.2, -1.1);
        println!("a: {}", a.to_str());
        println!("b: {}", b.to_str());

        println!("magnitude: {}", a.magnitude());
        println!("normalize: {}", a.normalize().to_str());
        println!("dot: {}", V3::dot(a, b));
        println!("cross: {}", V3::cross(a, b));
        println!("angle: {}", V3::angle(a, b));
        // println!("from_polar{:?}", a.to_polar().from_polar());
        // println!("to_polar{:?}", a.to_polar());
    }

    {
        let names = &["kara", "oko", "goma", "kuri"];
        let colors = &["white", "brown", "darkbrown", "darkbrown"];
        let dict = Dict::<&str, &str>::make_from_array(names, colors);
        for i in 0..dict.length() {
            println!("{}: {}", dict.get_key(i), dict.get_value(i));
        }
    }
}
