use rand::Rng;

pub fn bst(weights: &[f64]) -> i32 {
    if weights.len() <= 0 {
        return -1;
    }

    let mut totals = Vec::<f64>::new(); //  = vec![0. as f64; weights.len()];
    let mut total: f64 = 0.;
    for i in 0..weights.len() {
        total += weights[i];
        totals.push(total)
    }

    let mut gen = rand::thread_rng();
    let r: f64 = gen.gen_range(0.0..total);
    let mut top = weights.len() as i32;
    let mut bottom = 0;
    while top > bottom {
        let center: i32 = (bottom + top) / 2;
        if r > totals[center as usize] {
            bottom = center + 1;
        } else {
            let p: f64 = if center > 0 {
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

pub fn weighted<T>(items: &[T], weights: &[f64]) -> T
where
    T: Copy,
{
    return items[bst(weights) as usize];
}
