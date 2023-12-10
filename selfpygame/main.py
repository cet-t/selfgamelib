from src.vector2 import V2
from src.lottery import Lottery, LotteryPair
from src.mathf import Mathf
from src.trrne import trrne
from src.randomf import Rnd, STRTYPE


if __name__ == '__main__':
    a = V2(3, 6)
    b = V2(4, 1)
    # print(V2.distance(a, b))

    # t = tupletest(('kara', 10), ('oko', 7), ('kuri', 7), ('goma', 6))
    # # t = test('kara', 10, 'oko', 7, 'kuri', 7, 'goma', 6)
    # print(t.pair())
    # print(t.subjects())
    # print(t.weights())

    # pairs = LotteryPair(
    #     ('karachan', 1.3),
    #     ('okoge', 2.5),
    #     ('kuri', 5.2),
    #     ('goma', 5.2)
    # )
    # # print(Lottery.weighted(pairs=pairs))
    # print(Lottery.bst(weights=pairs.weights()))

    # percentage = LotteryPair([('SSR', 1), ('SR', 3), ('R', 96)])
    # ssr = []
    # sr = []
    # r = []
    # for _ in range(1000):
    #     choice = Lottery.weighted(percentage)
    #     if choice == 'SSR':
    #         ssr.append(choice)
    #     elif choice == 'SR':
    #         sr.append(choice)
    #     else:
    #         r.append(choice)
    # print(f'SSR: {len(ssr)}\nSR : {len(sr)}\nR  : {len(r)}')

    for i in range(1, 11, 1):
        print(Rnd.randstr(i, STRTYPE.MIX))
