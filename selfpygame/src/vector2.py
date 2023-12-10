import dataclasses
from typing import Any
import numpy as np
# from mathf import Mathf


@dataclasses.dataclass
class V2:
    x: float
    y: float

    def __add__(self, other) -> Any:
        if isinstance(other, V2):
            return V2(self.x + other.x, self.y + other.y)
        raise TypeError()

    def __sub__(self, other) -> Any:
        if isinstance(other, V2):
            return V2(self.x - other.x, self.y - other.y)
        raise TypeError()

    def __mul__(self, other) -> float | Any:
        if isinstance(other, V2):
            return self.x * other.y - self.y * other.x
        elif isinstance(other, (float, int)):
            return self.x * other.x + self.y * other.y
        raise TypeError()

    def __radd__(self, other) -> Any:
        if isinstance(other, V2):
            return V2(other.x + self.x, other.y + self.y)
        raise TypeError()

    def __rsub__(self, other) -> Any:
        if isinstance(other, V2):
            return V2(other.x - self.x, other.y - self.y)
        raise TypeError()

    def __str__(self) -> str:
        return f'({self.x},{self.y})'

    def magnitude(self) -> float:
        return np.sqrt(self.x ** 2 + self.y ** 2)

    @staticmethod
    def cross(a, b) -> Any:
        return a * b

    @staticmethod
    def dot(a, b) -> float:
        return a.x * b.x + a.y * b.y

    @staticmethod
    def distance(a, b) -> float:
        if isinstance(a, V2) and isinstance(b, V2):
            return np.round(np.sqrt(np.power(a.x - b.x, 2) + np.power(a.y - b.y, 2)), 3)
        raise TypeError()

    @staticmethod
    def min(a, b) -> Any:
        if not isinstance(a, V2) and not isinstance(b, V2):
            raise TypeError()
        return V2(np.min(a.x, b.x), np.min(a.y, b.y))

    @staticmethod
    def max(a, b) -> Any:
        if not isinstance(a, V2) and not isinstance(b, V2):
            raise TypeError()
        return V2(np.max(a.x, b.x), np.max(a.y, b.y))

    @staticmethod
    def angle(a, b) -> float:
        ''' 
        https://w3e.kanazawa-it.ac.jp/math/category/vector/henkan-tex.cgi?target=/math/category/vector/naiseki-wo-fukumu-kihonsiki.html&pcview=0 
        '''
        if not isinstance(a, V2) and not isinstance(b, V2):
            raise TypeError()
        abs_a: float = a.magnitude()
        abs_b: float = b.magnitude()
        return V2.dot(a, b) / abs_a * abs_b


ZERO = V2(0, 0)
ONE = V2(1, 1)
X = V2(1, 0)
Y = V2(0, 1)
