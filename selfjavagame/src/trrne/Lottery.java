package trrne;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class Lottery<TSubject> {
    public static int binarySearchTree(List<Float> $weights) throws Exception {
        if ($weights.isEmpty()) {
            throw new Exception();
        }

        List<Float> totals = new ArrayList<>($weights.size());
        float total = 0.f;
        for (int i = 0; i < $weights.size(); i++) {
            total += $weights.get(i);
            totals.add(total);
        }

        // float rnd = Mathf.randuniform(0f, total);
        float rnd = new Random().nextFloat(0f, total);
        int bottom = 0, top = totals.size() - 1;
        while (bottom < top) {
            int middle = (bottom + top) / 2;
            if (rnd > totals.get(middle)) {
                bottom = middle + 1;
            } else {
                float point = middle > 0 ? totals.get(middle - 1) : 0;
                if (rnd >= point) {
                    return middle;
                }
                top = middle;
            }
        }
        return top;
    }

    public static int bst(Float[] $weights) throws Exception {
        return binarySearchTree(Arrays.asList($weights));
    }

    public static <TSubject> TSubject weighted(LotteryPair<TSubject> $pair) throws Exception {
        if ($pair.size() <= 0) {
            throw new Exception();
        }
        return switch ($pair.size()) {
            case 1 -> $pair.items.get(0);
            default -> $pair.items.get(binarySearchTree($pair.weights));
        };
    }
}
