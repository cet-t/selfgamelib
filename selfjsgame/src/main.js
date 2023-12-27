class numjs {
    static pow(a, e) {
        let dst = a; 
        for (let i = 0; i < e; ++i) {
            dst *= a;
        }
        return dst;
    }

    static floor(a, digit) {
        let d = this.pow(10, digit);
        return Math.floor(a * d) / d;
    }
    
    static abs(a) {
        return a >= 0 ? a : -a;
    }
    
    static sign(a) {
        return a >= 0 ? a == 0 ? 0 : 1 : -1;
    }
    
    static twins(a, b) {
        return this.abs(a + b) < 1e-2;
    }
}

class V {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
    
    static add(a, b) {
        return new V(
            numjs.floor(a.x + b.x, 3),
            numjs.floor(a.y + b.y, 3)
        );
    }
    
    static sub(a, b) {
        return new V(
            numjs.floor(a.x - b.x, 3),
            numjs.floor(a.y - b.y, 3)
        );
    }

    static mul(a, b) {
        return new V(
            numjs.floor(a.x * b.x, 3),
            numjs.floor(a.y * b.y, 3)
        );
    }
    
    static div(a, b) {
        return new V(
            numjs.floor(a.x / b.x, 3),
            numjs.floor(a.y / b.y, 3)
        );
    }

    magnitude() {
        return numjs.floor(Math.sqrt(this.x * this.x + this.y * this.y), 3);
    }
    
    normalize() {
        return new V(
            numjs.floor(this.x / this.magnitude(), 3),
            numjs.floor(this.y / this.magnitude(), 3)
        );
    }
    
    static dot(a, b) {
        return numjs.floor(a.x * b.x + a.y * b.y, 3);
    }
    
    static angle(a, b) {
        const lal = a.magnitude(),
            lbl = b.magnitude();
        if (Math.abs(lal + lbl) < 1e-44) {
            return 0;
        }
        let dst = Math.acos(V.dot(a, b) / lal / lbl) * (180 / Math.PI);
        return numjs.floor(dst, 3);
    }
    
    str() {
        return "(" + this.x + "," + this.y + ")";
    }
}

function random(min, max) {
    return Number.MAX_SAFE_INTEGER * Math.random() % (max - min) + min;
}

class LotteryPair {
    constructor(pairs) {
        this.pairs = pairs;
        this.len = pairs.length;
        this.subjects = [];
        this.weights = [];
        for (let i = 0; i < pairs.length; ++i) {
            this.subjects.push(pairs[i][0]);
            this.weights.push(pairs[i][1]);
        }
    }
    
    get_weights() {
        return this.weights;
    }
    
    get_subjects() {
        return this.subjects;
    }
    
    get_total_weight() {
        return this.weights.reduce((dst, e) => dst += e);
    }
    
    // 各要素の確率
    get_percentage(digit = 16 + 1) {
        const total = this.weights.reduce((dst, e) => dst += e);
        let dst = [];
        for (let i = 0; i < this.len; ++i) {
            dst[i] = numjs.floor(this.weights[i] / total * 100, digit);
        }
        return dst;
    }
    
    // 重み付き抽選
    bst() {
        return this.subjects[lottery.bst(this.weights)];
    }
}

class lottery {
    static bst(weights) {
        if (weights.length <= 0) {
            return -1;
        }
        
        let total = 0;
        let totals = [];
        for (let i = 0; i < weights.length; ++i) {
            total += weights[i];
            totals.push(total);
        }
        
        const R = random(0, total);
        let bottom = 0;
        let top = totals.length - 1;
        while (bottom < top) {
            const MID = numjs.floor((bottom + top) / 2, 0);
            if (R > totals[MID]) {
                bottom = MID + 1
            } else {
                var p = MID > 0 ? totals[MID - 1] : 0.0;
                if (R >= p) {
                    return MID;
                }
                top = MID;
            }
        }
        return top;
    }
}

// function index(title, func) {
//     const line = "-----";
//     console.log(line + " " + title + " " + line);
//     console.log(func());
//     var underline = line + line;
//     for (let i = 0; i < title.length + 2; ++i) {
//         underline += "-";
//     }
//     console.log(underline); 
// }

function header(title) { console.log("----- " + title + " -----"); }
function footer() { console.log("------------------"); }

{
    header("vector");
    const a = new V(2.8, -1.2), b = new V(-2.3, 1.8);
    console.log("a: " + a.str());
    console.log("b: " + b.str());
    console.log("add: " + V.add(a, b).str());
    console.log("sub: " + V.sub(a, b).str());
    console.log("mul: " + V.mul(a, b).str());
    console.log("div: " + V.div(a, b).str());
    console.log("a magnitude: " + a.magnitude());
    console.log("b normalize: " + b.normalize().str());
    console.log("dot: " + V.dot(a, b));
    console.log("angle: " + V.angle(a, b));
    footer();
}

{
    header("lottery");
    const N = 3, L = 1e6;
    // const weights = [1, 2, 3];
    // const total = weights.reduce((dst, e) => dst += e);
    // const rarity = [ "大吉", "吉", "凶" ];
    const pairs = new LotteryPair([["a", 3], ["b", 2], ["c", 1]]);
    // console.log(pair.weights);
    // const pairs = { "大吉": 0.1, "中吉": 1, "小吉": 10, "末吉": 50, "吉  ": 100 };
    let counter = [0, 0, 0];
    for (let j = 0; j < L; ++j) {
        // counter[lottery.bst(weights)]++;
        counter[lottery.bst(pairs.get_weights())]++;
    }
    console.log(counter);
    let dst = "";
    for (let i = 0; i < N; ++i) {
        // dst += rarity[i] + "(" + numjs.floor(weights[i] / total * 100, 2) + "%): " +
        //     counter[i] + "(" + numjs.floor(counter[i] / L * 100, 2) + "%)";
        dst += pairs.subjects[i] + "(" +
            numjs.floor(pairs.get_weights()[i] / pairs.get_total_weight() * 100, 2) + "%): " +
            counter[i] + "(" + numjs.floor(counter[i] / L * 100, 2) + "%)";
        if (i < N - 1) {
            dst += "\n";
        }
    }
    console.log(dst);
    // let pair = new LotteryPair([["SSR", 4], ["SR", 43], ["R", 53]]);
    // for (let i = 1; i <= 100; ++i) {
    //     console.log(i + ": " + pair.bst());
    // }
    // console.log(pair.get_percentage());
    footer();
}