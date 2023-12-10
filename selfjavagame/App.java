import trrne.*;
import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("hello world!");
        Tuple<String, Float>[] pairs = new Tuple[] {
                new Tuple<>("R", 1.0f),
                new Tuple<>("SR", 3.0f),
                new Tuple<>("SSR", 96.0f)
        };

        System.out.println(Mathf.randuniform(0, 10));

        List<String> R = new ArrayList<>(), SR = new ArrayList<>(), SSR = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            var choice = Lottery.weighted(new LotteryPair<String>(Arrays.asList(pairs)));
            if (choice == "R") {
                R.add(choice);
            } else if (choice == "SR") {
                SR.add(choice);
            } else {
                SSR.add(choice);
            }
        }
        System.out.println("R : " + R.size() + "\nSR : " + SR.size() + "\nSSR: " + SSR.size());
    }
}
