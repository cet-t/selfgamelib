from dataclasses import dataclass
from typing import Any
from numpy import *


@dataclass
class V2:
    x: float
    y: float

    def mag(self): return sqrt(self.x * self.x + self.y * self.y)
    def nor(self): return V2(self.x / self.mag(), self.y / self.mag())

    @staticmethod
    def dot(a, b):
        return (a.x * b.x + a.y * b.y) if isinstance(a, V2) and isinstance(b, V2) else 720

    # Operators

    def __add__(self, a):
        ''' 
        self + a 
        '''
        if isinstance(a, V2):
            return V2(self.x + a.x, self.y + a.y)
        raise TypeError()

    def __truediv__(self, a):
        '''
        self / a
        '''
        if isinstance(a, V2):
            return V2(self.x / a.x, self.y / a.y)
        elif isinstance(a, (int, float)):
            return V2(self.x / a, self.y / a)
        raise TypeError()

    def __floordiv__(self, a):
        '''
        self // a
        '''
        if isinstance(a, V2):
            return V2(self.x / a.x, self.y / a.y)
        elif isinstance(a, (float, int)):
            return V2(self.x / a, self.y / a)
        raise TypeError()

    def __and__(self, a):
        '''
        self & a
        '''
        raise Exception()

    def __xor__(self, a):
        '''
        self ^ a
        '''
        raise Exception()

    def __invert__(self):
        '''
        ~self
        '''
        raise Exception()

    def __pow__(self, a):
        '''
        self ** a
        '''
        if isinstance(a, V2):
            return V2(self.x ** a.x, self.y ** a.y)
        elif isinstance(a, (int, float)):
            return V2(self.x ** a, self.y ** a)
        raise TypeError()

    def __is__(self, a):
        '''
        self is a
        '''
        if isinstance(a, V2):
            return id(self) == id(a)
        raise TypeError()

    def __is_not__(self, a):
        '''
        self is not a
        '''
        if isinstance(a, V2):
            return id(self) != id(a)
        raise TypeError()

    def __setitem__(self, k, v):
        '''
        self[k] = v
        '''
        if isinstance(k, int) and isinstance(v, V2) and 0 <= k <= 1:
            if k == 0:
                self.x = v
            elif k == 1:
                self.y = v
        raise TypeError()

    def __delitem__(self, k):
        '''
        del self[k]
        '''
        if isinstance(k, int) and 0 <= k <= 1:
            if k == 0:
                del self.x
            elif k == 1:
                del self.y
        raise TypeError()

    def __getitem__(self, k):
        '''
        self[k]
        '''
        if isinstance(k, int) and 0 <= k <= 1:
            if k == 0:
                return self.x
            elif k == 1:
                return self.y
        raise TypeError()

    def __lshift__(self, a):
        '''
        self << a
        '''
        if isinstance(a, int):
            return V2(self.x << a, self.y << a)
        raise TypeError()

    def __mod__(self, a):
        '''
        self % a
        '''
        if isinstance(a, V2):
            return V2(self.x % a.x, self.y % a.x)
        elif isinstance(a, (int, float)):
            return V2(self.x % a, self.y % a)
        raise TypeError()

    def __mul__(self, other):
        '''
        self * a
        '''
        if isinstance(other, V2):
            return V2(self.x * other.x, self.y * other.y)
        elif isinstance(other, (float, int)):
            return V2(self.x * other, self.y * other)
        raise TypeError()

    def __neg__(self):
        '''
        -self
        '''
        return V2(-self.x, -self.y)

    def __pos__(self):
        '''
        +self
        '''
        return V2(+self.x, +self.y)

    def __rshift__(self, a):
        '''
        shift >> a
        '''
        if isinstance(a, int):
            return V2(self.x >> a, self.y >> a)
        raise TypeError()

    def __sub__(self, a):
        '''
        self - a
        '''
        if isinstance(a, V2):
            return V2(self.x - a.x, self.y - a.y)
        raise TypeError()

    def __lt__(self, a):
        '''
        self < a
        '''
        if isinstance(a, V2):
            return self.x < a.x and self.y < a.y
        raise TypeError()

    def __le__(self, a):
        '''
        self <= a
        '''
        if isinstance(a, V2):
            return self.x <= a.x and self.y <= a.y
        raise TypeError()

    def __eq__(self, a):
        '''
        self == a
        '''
        if isinstance(a, V2):
            return self.x == a.x and self.y == a.y
        raise TypeError()

    def __ne__(self, a):
        '''
        self != a
        '''
        if isinstance(a, V2):
            return self.x != a.x and self.y != a.y
        raise TypeError()

    def __gt__(self, a):
        '''
        self > a
        '''
        if isinstance(a, V2):
            return self.x > a.x and self.y > a.y
        raise TypeError()

    def __ge__(self, a):
        '''
        self >= a
        '''
        if isinstance(a, V2):
            return self.x >= a.x and self.y >= a.y
        raise TypeError()

    def __iadd__(self, a):
        '''
        self += a
        '''
        if isinstance(a, V2):
            self.x += a.x
            self.y += a.y
            return self
        raise TypeError()

    def __ifloordiv__(self, a):
        '''
        self //= a
        '''
        if isinstance(a, V2):
            return self.__floordiv__(a)
        raise TypeError()

    def __iadd__(self, a):
        '''
        self += a
        '''
        if isinstance(a, V2):
            self.__add__(a)
            return self
        raise TypeError()

    def __ilshift__(self, a):
        '''
        self <<= a
        '''
        if isinstance(a, int):
            return self.__lshift__(a)
        raise TypeError()

    def __imod__(self, a):
        '''
        self %= a
        '''
        if isinstance(a, V2):
            return self.__mod__(a)
        elif isinstance(a, (int, float)):
            return self.__mod__(a)
        raise TypeError()

    def __imul__(self, a):
        '''
        self *= a
        '''
        if isinstance(a, V2):
            return self.__mul__(a)
        elif isinstance(a, (int, float)):
            return self.__mul__(a)
        raise TypeError()

    def __ipow__(self, a):
        '''
        self **= a
        '''
        if isinstance(a, V2):
            return self.__pow__(a)
        elif isinstance(a, (int, float)):
            return self.__pow__(a)
        raise TypeError()

    def __irshift__(self, a):
        '''
        self >>= a
        '''
        if isinstance(a, V2):
            return self.__rshift__(a)
        elif isinstance(a, (int, float)):
            return self.__rshift__(a)
        raise TypeError()

    def __isub__(self, a):
        '''
        self -= a
        '''
        if isinstance(a, V2):
            return self.__sub__(a)
        elif isinstance(a, (int, float)):
            return self.__sub__(a)
        raise TypeError()

    def __itruediv__(self, a):
        '''
        self /= a
        '''
        if isinstance(a, V2):
            return self.__truediv__(a)
        elif isinstance(a, (int, float)):
            return self.__truediv__(a)
        raise TypeError()

    def __ixor__(self, a):
        '''
        self ^= a
        '''
        if isinstance(a, V2):
            return self.__xor__(a)
        elif isinstance(a, (int, float)):
            return self.__xor__(a)
        raise TypeError()

    def __str__(self): return f'({self.x},{self.y})'
    def to_str(self): return self.__str__()


ZERO = V2(0, 0)
ONE = V2(1, 1)
X = V2(1, 0)
Y = V2(0, 1)


@dataclass
class V3:
    x: float
    y: float
    z: float
