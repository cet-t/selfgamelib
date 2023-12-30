import numpy as np

fi = float | int

PI = 3.141592653589793
DEG_TO_RAD = PI * 2.0 / 360.0
RAD_TO_DEG = 1.0 / DEG_TO_RAD


class M:
    @staticmethod
    def to_rad(deg: float) -> fi: return deg * DEG_TO_RAD

    @staticmethod
    def to_deg(rad: float) -> fi: return rad * RAD_TO_DEG

    @staticmethod
    def round(n: fi, digit: int = 1) -> fi:
        return (n * 10 ** digit * 2 + 1) // 2 / 10 ** digit

    @staticmethod
    def floor(n: fi, digit: int) -> fi:
        pow: float = M.pow(10, digit)
        return np.floor(n * pow) / pow

    @staticmethod
    def abs(n: fi) -> fi: return n if n >= 0 else -n

    @staticmethod
    def sign(n: fi) -> int: return 1 if n > 0 else -1 if n < 0 else 0

    @staticmethod
    def pow(n: fi, e: int) -> fi:
        if e == 0:
            return 1
        dst = n
        for _ in range(1 if M.sign(e) == 1 else -1, e, 1):
            dst *= n
        return dst

    @staticmethod
    def digit(n) -> int: return len(str(n).replace('.', ''))

    @staticmethod
    def clamp(target, min: float, max: float) -> fi:
        return min if target < min else max if target > max else target

    @staticmethod
    def lerp(o, p, time) -> float:
        return o + (p - o) * M.clamp(time)

    @staticmethod
    def eratosthenes(n: int) -> list[int]:
        flags: list[bool] = [True] * (n+1)
        flags[0], flags[1] = False, False
        # flags[0:1] = False

        for i in range(2, int(n**0.5)+1):
            if flags[i]:
                for j in range(2*i, n+1, i):
                    flags[j] = False
        return [i for i in range(2, n+1) if flags[i]]

    @staticmethod
    def min(a: float, b: float) -> float: return a if a < b else b

    @staticmethod
    def max(a: float, b: float) -> float: return a if a > b else b
