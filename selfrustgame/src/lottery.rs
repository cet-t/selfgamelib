use rand::Rng;

pub fn bst(weights: &[f32]) -> i32 {
    if weights.len() <= 0 {
        return -1;
    }

    let mut totals = Vec::<f32>::new(); //  = vec![0. as f32; weights.len()];
    let mut total: f32 = 0.;
    for i in 0..weights.len() {
        total += weights[i];
        totals.push(total)
    }

    let mut gen = rand::thread_rng();
    let r: f32 = gen.gen_range(0.0..total);
    let mut top = weights.len() as i32;
    let mut bottom = 0;
    while top > bottom {
        let center: i32 = (bottom + top) / 2;
        if r > totals[center as usize] {
            bottom = center + 1;
        } else {
            let p: f32 = if center > 0 {
                totals[center as usize - 1]
            } else {
                0.
            };
            if r >= p {
                return center;
            }
            top = center;
        }
    }
    top
}

pub fn weighted<T>(items: &[T], weights: &[f32]) -> T
where
    T: Copy,
{
    return items[bst(weights) as usize];
}

// pub struct LotteryPair<TItem, const N: usize> {
//     pub items: [TItem; N],
//     pub weights: [f32; N],
// }

// impl<TItem, const N: usize> LotteryPair<TItem, N> {
//     pub fn new(items: [TItem; N], weights: [f32; N]) -> Self {
//         LotteryPair { items, weights }
//     }
// }
