﻿from random import uniform
import numpy as np

from src.v import *
from src.lottery import *
from src.m import M
from src.trrne import *
from src.rand import *
from src.secret import *


N: str = '\n'


@prefix('v2')
def v2():
    dst = ''

    a = V2(uniform(-10, 10), uniform(-10, 10))
    b = V2(uniform(-10, 10), uniform(-10, 10))
    dst += '+a      : ' + (+a).__str__() + N
    dst += '-b      : ' + (-b).__str__() + N
    dst += 'a+b     : ' + (a+b).__str__() + N
    dst += 'a-b     : ' + (a-b).__str__() + N
    dst += 'a*b     : ' + (a*b).__str__() + N
    dst += 'a/b     : ' + (a/b).__str__() + N
    # a += b
    # a -= b
    # a *= b
    # a /= b

    print(dst)


@prefix('lottery')
def lottery():
    dst: str = ''

    L: int = 100000
    weights: list[float] = [1.1, 0.75, 0.8, 0.79]
    names: list[str] = ['kara', 'goma', 'dngr', 'ohgi']
    length = len(weights)
    # pairs = LotteryPair([('kara', 1.1), ('goma', 0.75), ('dngr', 0.8), ('ohgi', 0.79)])
    counters: list[int] = [0] * length
    for _ in range(L):
        # a = Lottery.weighted(pairs)
        counters[Lottery.bst(weights)] += 1
    for i in range(length):
        dst += names[i] + \
            '(' + str(M.floor(weights[i] / length * 100, 2)) + '%): '
        dst += str(counters[i]) + \
            '(' + str(M.floor(counters[i] / L * 100, 2)) + '%)'
        if i < length-1:
            dst += N

    print(dst)


@prefix('aes')
def aes():
    dst = ''

    src = 'fugou'
    dst += 'src     : ' + src + N
    pw: str = 'password'
    crypto = MyAES(pw)
    en = crypto.en(src)
    dst += 'en      : ' + str(en) + N
    de = crypto.de(en)
    dst += 'de      : ' + de.decode('utf-8')

    print(dst)


@prefix('random')
def rand():
    dst = ''
    dst += Rand.randstr(8, STRTYPE.ALPHABET) + N
    dst += Rand.randstr(8, STRTYPE.ALPHABET) + N
    dst += Rand.randstr(8, STRTYPE.ALPHABET) + N
    dst += Rand.randstr(8, STRTYPE.ALPHABET) + N
    dst += Rand.randstr(8, STRTYPE.ALPHABET) + N
    dst += Rand.randstr(8, STRTYPE.ALPHABET) + N

    print(dst)


if __name__ == '__main__':
    v2()
    lottery()
    aes()
    rand()
