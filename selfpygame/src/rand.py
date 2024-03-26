from random import SystemRandom
from enum import Enum


class STRTYPE(Enum):
    MIX = 0
    ALPHABET = 1
    JP = 2
    NUM = 3


class Rand:
    __ALPHABETS: str = 'abcdefghijklmnopqrstuvwxyz'
    __NUMBERS: str = '1234567890'
    __JAPANESES: str = 'あいうえおかきくけこがぎぐげごさしすせそざじずぜぞたちつてとだぢづでどなにぬねのはひふへほばびぶべぼぱぴぷぺぽまみむめもやゆよらりるれろわをん'

    @staticmethod
    def normal_char(n: int) -> list:
        chars = list(Rand.__ALPHABETS)
        ls: list = []
        for _ in range(n := len(chars)-1 if n > len(chars) else n-1):
            ls.append(chars[Rand().randint(0, n)])
        return ls

    @staticmethod
    def randstr(n: int, type=STRTYPE.MIX) -> str:
        if not isinstance(n, int) or not isinstance(type, STRTYPE):
            raise TypeError

        def mixer(src: str) -> str:
            dst: str = ''
            for _ in range(n):
                dst += src[Rand.randint(max=len(src)-1)]
            return dst

        if type == STRTYPE.ALPHABET:
            return mixer(Rand.__ALPHABETS)
        elif type == STRTYPE.JP:
            return mixer(Rand.__JAPANESES)
        elif type == STRTYPE.NUM:
            return mixer(Rand.__NUMBERS)
        else:
            return mixer(Rand.__ALPHABETS + Rand.__NUMBERS)

    @staticmethod
    def randint(min=0, max=0) -> int:
        if isinstance(min, int) or isinstance(max, int):
            return SystemRandom().randint(int(min), int(max))
        raise TypeError

    @staticmethod
    def randfloat(min=0.0, max=0.0) -> float:
        return SystemRandom().uniform(min, max)

# https://qiita.com/mk668a/items/d53515817c41e22e77f0
# https://www.hanachiru-blog.com/entry/2019/02/01/190918
