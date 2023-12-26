package trrne;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class Lottery<TSubject> {
    public static int binarySearchTree(List<Double> $weights) throws Exception {
        if ($weights.isEmpty()) {
            throw new Exception();
        }

        List<Double> totals = new ArrayList<>($weights.size());
        double total = 0.f;
        for (int i = 0; i < $weights.size(); i++) {
            total += $weights.get(i);
            totals.add(total);
        }

        // double rnd = Mathf.randuniform(0f, total);
        double rnd = new Random().nextDouble(0f, total);
        int bottom = 0, top = totals.size() - 1;
        while (bottom < top) {
            int middle = (bottom + top) / 2;
            if (rnd > totals.get(middle)) {
                bottom = middle + 1;
            } else {
                double point = middle > 0 ? totals.get(middle - 1) : 0;
                if (rnd >= point) {
                    return middle;
                }
                top = middle;
            }
        }
        return top;
    }

    public static int bst(Double[] $weights) throws Exception {
        return binarySearchTree(Arrays.asList($weights));
    }
}
