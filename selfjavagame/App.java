import java.lang.Math;
import trrne.*;

public class App {
    public static void main(String[] args) throws Exception {
        // Tuple<String, Float>[] pairs = new Tuple[] {
        // new Tuple<>("R", 1.0f),
        // new Tuple<>("SR", 3.0f),
        // new Tuple<>("SSR", 96.0f)
        // };

        // System.out.println(Mathf.randuniform(0, 10));

        // List<String> R = new ArrayList<>(), SR = new ArrayList<>(), SSR = new
        // ArrayList<>();
        // for (int i = 0; i < 100; i++) {
        // var choice = Lottery.weighted(new LotteryPair<String>(Arrays.asList(pairs)));
        // if (choice == "R") {
        // R.add(choice);
        // } else if (choice == "SR") {
        // SR.add(choice);
        // } else {
        // SSR.add(choice);
        // }
        // }
        // System.out.println("R : " + R.size() + "\nSR : " + SR.size() + "\nSSR: " +
        // SSR.size());

        int N = 5, L = 100000;
        Double weights[] = { 0.1, 1.0, 20.0, 50.0, 100.0 };
        String rarity[] = { "UR", "SSR", "SR", "R", "C" };
        int counters[] = { 0, 0, 0, 0, 0 };
        for (int i = 0; i < L; ++i) {
            ++counters[Lottery.bst(weights)];
        }
        double total = 0.0;
        for (var w : weights) {
            total += w;
        }
        for (int i = 0; i < N; ++i) {
            System.out.println(
                    rarity[i] + "(" + Mathf.floor(weights[i] / total * 100, 2) + "%): " + counters[i] + "("
                            + Mathf.floor((double) counters[i] / (double) L * 100, 2) + "%)");
        }
    }
}
