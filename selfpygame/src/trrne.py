class trrne:
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
            base = trrne.delete(base, befores[i])
        return base
