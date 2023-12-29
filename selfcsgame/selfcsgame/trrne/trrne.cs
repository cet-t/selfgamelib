#pragma warning disable CS8981, IDE1006

namespace trrne;

public static class trrne
{
    public static void ForEach<T>(this T[] array, Action<T> action) => Array.ForEach(array, action);
}