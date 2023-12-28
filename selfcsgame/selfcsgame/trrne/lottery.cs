namespace trrne;

public class LotteryPair<T>
{
    readonly List<T> subjects = [];
    readonly List<double> weights = [];

    public LotteryPair(params (T subject, double weight)[] pairs)
    {
        Len = pairs.Length;
        Array.ForEach(pairs, pair =>
        {
            subjects.Add(pair.subject);
            weights.Add(pair.weight);
        });
    }

    public int Len { get; private set; }

    public T[] Subjects => [.. subjects];
    public double[] Weights => [.. weights];

    public double TotalWeights => weights.Sum();

    public object this[int index] => (subjects[index], weights[index]);

    public T Weighted() => Subjects[Lottery.Bst(Weights)];
}

public static class Lottery
{
    readonly static Random rand;
    static Lottery() => rand = new();

    public static int Bst(params double[] weights)
    {
        if (weights.Length <= 0)
        {
            return -1;
        }

        double[] totals = new double[weights.Length];
        double total = 0;
        for (int i = 0; i < weights.Length; i++)
        {
            total += weights[i];
            totals[i] = total;
        }
        double random = rand.NextDouble() * total;
        int bottom = 0, top = totals.Length - 1;
        while (bottom < top)
        {
            int middle = (bottom + top) / 2;
            if (random > totals[middle])
            {
                bottom = middle + 1;
            }
            else
            {
                if (random >= (middle > 0 ? totals[middle - 1] : 0))
                {
                    return middle;
                }
                top = middle;
            }
        }
        return top;
    }
}