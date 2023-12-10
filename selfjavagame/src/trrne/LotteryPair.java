package trrne;

import java.util.ArrayList;
import java.util.List;

public class LotteryPair<TItem> {
    List<Tuple<TItem, Float>> pairs;
    public List<TItem> items = new ArrayList<>();
    public List<Float> weights = new ArrayList<>();

    public LotteryPair(List<Tuple<TItem, Float>> $pairs) {
        pairs = $pairs;
        for (int i = 0; i < pairs.size(); i++) {
            items.add($pairs.get(i).item1);
            weights.add($pairs.get(i).item2);
        }
    }

    public int size() {
        return pairs.size();
    }
}
