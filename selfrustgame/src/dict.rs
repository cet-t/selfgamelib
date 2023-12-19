use std::cmp::min;
use std::ptr::eq;

#[derive(Debug, Clone)]
pub struct Dict<TK, TV> {
    pub keys: Vec<TK>,
    pub values: Vec<TV>,
}

pub trait Dicte<TK, TV>
where
    TK: Default + Clone + Sized + Copy,
    TV: Default + Clone + Sized + Copy,
{
    fn new() -> Dict<TK, TV>;
    fn length(&self) -> usize;
    fn make_from_array(keys: &[TK], values: &[TV]) -> Dict<TK, TV>;
    fn make_from_vec(keys: Vec<TK>, values: Vec<TV>) -> Dict<TK, TV>;
    fn add(&mut self, key: TK, value: TV);
    fn add_key(&mut self, key: TK);
    fn add_value(&mut self, value: TV);
    fn add_range(&mut self, src_key: Vec<TK>, src_value: Vec<TV>, begin: usize, end: usize);
    fn remove(&mut self, key: &TK, value: &TV);
    fn remove_from_key(&mut self, key: &TK);
    fn remove_from_value(&mut self, value: &TV);
    fn remove_at(&mut self, index: usize);
    fn remove_range(&mut self, begin: usize, end: usize);
}

#[allow(unused)]
impl<TK, TV> Dicte<TK, TV> for Dict<TK, TV>
where
    TK: Default + Clone + Sized + Copy,
    TV: Default + Clone + Sized + Copy,
{
    fn new() -> Dict<TK, TV> {
        Dict {
            keys: Vec::new(),
            values: Vec::new(),
        }
    }

    fn length(&self) -> usize {
        self.keys.len()
    }

    fn make_from_array(keys: &[TK], values: &[TV]) -> Dict<TK, TV> {
        let mut k = Vec::<TK>::new();
        let mut v = Vec::<TV>::new();
        for i in 0..keys.len() {
            k.push(keys[i]);
            v.push(values[i]);
        }
        Dict { keys: k, values: v }
    }

    fn make_from_vec(keys: Vec<TK>, values: Vec<TV>) -> Dict<TK, TV> {
        Dict { keys, values }
    }

    fn add(&mut self, key: TK, value: TV) {
        self.keys.push(key);
        self.values.push(value);
    }

    fn add_key(&mut self, key: TK) {
        self.keys.push(key);
        self.values.push(TK::default());
    }

    fn add_value(&mut self, value: TV) {
        self.keys.push(TV::default());
        self.values.push(value);
    }

    fn add_range(&mut self, src_key: Vec<TK>, src_value: Vec<TV>, begin: usize, end: usize) {
        if end >= src_key.len() || begin > end {
            return;
        }

        let range: usize = min(end - begin + 1, src_key.len() - begin);

        for i in begin..=end {
            if i - begin >= range {
                break;
            }
            self.keys.push(src_key[i]);
            self.values.push(src_value[i]);
        }
    }

    fn remove(&mut self, key: &TK, value: &TV) {
        for i in 0..self.keys.len() {
            if eq(&self.keys[i], key) && eq(&self.values[i], value) {
                self.keys.remove(i);
                self.values.remove(i);
                break;
            }
        }
    }

    fn remove_from_key(&mut self, key: &TK) {
        for i in 0..self.keys.len() {
            if eq(&self.keys[i], key) {
                self.keys.remove(i);
                self.values.remove(i);
                break;
            }
        }
    }

    fn remove_from_value(&mut self, value: &TV) {
        for i in 0..self.keys.len() {
            if eq(&self.values[i], value) {
                self.keys.remove(i);
                self.values.remove(i);
                break;
            }
        }
    }

    fn remove_at(&mut self, index: usize) {
        self.keys.remove(index);
        self.values.remove(index);
    }

    fn remove_range(&mut self, begin: usize, end: usize) {
        for i in 0..self.length() {
            if i >= begin && i <= end {
                self.keys.remove(i);
                self.values.remove(i);
            }
        }
    }
}
