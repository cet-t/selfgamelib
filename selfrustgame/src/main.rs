pub mod dict;
pub mod lottery;
pub mod traits;
pub mod trrne;
pub mod v2;
pub mod v3;

// use std::vec;

use dict::*;
// use lottery::*;
// use traits::*;
use v2::*;
use v3::*;

fn space2(title: &str, design: char, body: String) {
    let designed_line = &mut String::new();
    for _ in 0..32 {
        designed_line.push(design);
    }
    let deco = "*";
    println!(
        "{}{} {} {}{}",
        designed_line, deco, title, deco, designed_line
    );
    print!("{}", body);
    let underline = &mut String::new();
    for _ in 0..title.len() + deco.len() + designed_line.len() * 2 + 3 {
        underline.push(design);
    }
    println!("{}", underline);
}

fn main() {
    {
        space2(
            "v2!",
            '-',
            (|| -> String {
                let dst = &mut String::new();
                let a: &mut V2 = &mut V2::new(1., 2.);
                let b: &mut V2 = &mut V2::new(8., -4.);
                dst.push_str(&format!("a: {:?}\n", a.to_str()));
                dst.push_str(&format!("b: {:?}\n", b.to_str()));
                dst.push_str(&format!("magnitude: {:?}\n", a.magnitude()));
                dst.push_str(&format!("normalize: {:?}\n", a.normalize().to_str()));
                dst.push_str(&format!("dot: {:?}\n", V2::dot(a, b)));
                dst.push_str(&format!("cross: {:?}\n", V2::cross(a, b)));
                dst.push_str(&format!("angle: {:?}\n", V2::angle(a, b)));
                dst.push_str(&format!("from_polar: {:?}\n", a.to_polar().from_polar()));
                dst.push_str(&format!("to_polar: {:?}\n", a.to_polar()));
                return dst.to_string();
            })(),
        );
    }

    {
        let dst = &mut String::new();

        const N: usize = 5;
        const L: usize = 100000;
        let rarity: [&str; N] = ["UR", "SSR", "SR", "R", "C"];
        let weights: [f64; N] = [0.1, 1.0, 20.0, 50.0, 100.0];
        let mut counters: [i32; N] = [0; N];
        for _ in 0..L {
            for i in 0..N {
                let choice = rarity[lottery::bst(&weights) as usize];
                if choice == rarity[i] {
                    counters[i] += 1;
                }
            }
        }
        let total: f64 = weights.iter().sum();
        for i in 0..N {
            dst.push_str(&format!(
                "{}({:.2}%): {}\n",
                rarity[i],
                weights[i] / total * 100.0,
                counters[i]
            ));
        }

        space2("lottery!", '-', dst.to_string());
        /*
        UR(0.06%): 54
        SSR(0.58%): 601
        SR(11.69%): 11565
        R(29.22%): 29225
        C(58.45%): 58147
        */
    }

    {
        let dst = &mut String::new();

        let a: &mut V3 = &mut V3::new(1.1, -2.2, 3.3);
        let b: &mut V3 = &mut V3::new(-3.3, 2.2, -1.1);
        dst.push_str(&format!("a: {}", a.to_str()));
        dst.push_str(&format!("b: {}", b.to_str()));
        dst.push_str(&format!("magnitude: {}", a.magnitude()));
        dst.push_str(&format!("normalize: {}", a.normalize().to_str()));
        dst.push_str(&format!("dot: {}", V3::dot(a, b)));
        dst.push_str(&format!("cross: {}", V3::cross(a, b)));
        dst.push_str(&format!("angle: {}", V3::angle(a, b)));
        dst.push_str(&format!("from_polar{:?}", a.to_polar().from_polar()));
        dst.push_str(&format!("to_polar{:?}", a.to_polar()));

        space2("v3!", '-', dst.to_string());
    }

    {
        let dst = &mut String::new();

        let names = &["kara", "oko", "goma", "kuri"];
        let colors = &["white", "brown", "darkbrown", "darkbrown"];
        let dict = Dict::<&str, &str>::make_from_array(names, colors);
        for i in 0..dict.length() {
            dst.push_str(&format!("{}: {}\n", dict.get_key(i), dict.get_value(i)));
        }

        space2("dict!", '-', dst.to_string());
    }

    // let a = |x: i32| x * x;
    // println!("{}", a(2));
}
