from typing import Generic, TypeVar
import random

TSubject = TypeVar('TSubject')


class LotteryPair(Generic[TSubject]):
    def __init__(self, pairs: list[tuple[TSubject, float]]) -> None:
        super().__init__()
        self.pairs: list[tuple[TSubject, float]] = pairs
        self.subjects: list[TSubject] = []
        self.weights: list[float] = []
        for i in range(len(pairs)):
            self.subjects.append(pairs[i][0])
            self.weights.append(pairs[i][1])

    def size(self) -> int:
        return len(self.pairs)


class Lottery(Generic[TSubject]):
    @staticmethod
    def bst(weights: list[float]) -> int:
        '''二分探索木'''
        if len(weights) <= 0:
            raise Exception('からっぽやんけ')

        totals: list[float] = []
        total: float = 0.0
        for i in range(len(weights)):
            total += weights[i]
            totals.append(total)
        for i in totals:
            print(f'totals: {i}')

        rnd: float = random.uniform(0, total)
        bottom: int = 0
        top: int = len(totals)-1
        while bottom < top:
            center: int = int((bottom+top)/2)
            if rnd > totals[center]:
                bottom = center+1
            else:
                p: float = totals[center-1] if center > 0 else 0.0
                if rnd >= p:
                    return center
                top = center
        return top

    @staticmethod
    def weighted(pairs: LotteryPair[TSubject]) -> TSubject:
        if pairs.size() <= 0:
            raise Exception()
        return pairs.subjects[Lottery.bst(pairs.weights)] if pairs.size() != 1 else pairs.subjects[0]
