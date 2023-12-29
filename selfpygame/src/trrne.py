@staticmethod
def replace_lump(base: str, befores: list[str], after: str) -> str:
    for i in range(len(befores)):
        base = base.replace(befores[i], after)
    return base


@staticmethod
def delete(base: str, before: str) -> str:
    return base.replace(before, "")


@staticmethod
def delete_lump(base: str, befores: list[str]) -> str:
    for i in range(len(befores)):
        base = delete(base, befores[i])
    return base


def deco_s_deco(func):
    '''
    https://qiita.com/nshinya/items/b6746a0c07e9e20389e8
    '''
    def param(*args, **kwargs):
        def wrap(f):
            return func(f, *args, **kwargs)
        return wrap
    return param


@deco_s_deco
def prefix(func, prefix: str):
    def wrap(*args, **kwargs):
        line = '*------------------------------*'
        print(line, prefix, line)
        r = func(*args, **kwargs)
        sfx: str = ''
        for i in range(end := len(prefix) + 2 + len(line) * 2):
            sfx += '*' if i == 0 or i == end-1 else '-'
        print(sfx)
        return r
    return wrap
