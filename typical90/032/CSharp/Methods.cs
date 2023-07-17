using System;
using System.Collections.Generic;
using System.Linq;
using BenchmarkDotNet.Attributes;

//[ShortRunJob]
public class Methods
{
    static readonly int n = 10;
    static readonly bool[][] dis = {
        new bool[] { false, false, false, true, true, true, false, false, false, false },
        new bool[] { false, false, true, false, false, true, false, false, false, false },
        new bool[] { false, true, false, false, false, false, false, false, false, true },
        new bool[] { true, false, false, false, false, false, false, false, false, false },
        new bool[] { true, false, false, false, false, false, false, true, false, false },
        new bool[] { true, true, false, false, false, false, false, false, false, true },
        new bool[] { false, false, false, false, false, false, false, false, false, true },
        new bool[] { false, false, false, false, true, false, false, false, false, true },
        new bool[] { false, false, false, false, false, false, false, false, false, false },
        new bool[] { false, false, true, false, false, true, true, true, false, false },
    };
    
    static readonly int[][] a = {
        new int[] { 431, 228, 912, 801, 982, 739, 480, 773, 948, 294 },
        new int[] { 516, 879, 402, 951, 336, 680, 281, 639, 373, 995 },
        new int[] { 786, 345, 763, 646, 882, 845, 126, 97, 537, 355 },
        new int[] { 305, 944, 814, 15, 951, 46, 12, 487, 680, 289 },
        new int[] { 723, 401, 270, 750, 98, 720, 734, 532, 380, 836 },
        new int[] { 392, 593, 292, 478, 252, 128, 173, 543, 821, 964 },
        new int[] { 12, 47, 134, 536, 853, 372, 866, 509, 293, 555 },
        new int[] { 728, 208, 306, 150, 404, 791, 765, 67, 884, 991 },
        new int[] { 893, 942, 827, 340, 501, 540, 600, 875, 637, 207 },
        new int[] { 529, 122, 303, 860, 736, 128, 852, 489, 739, 423 },
    };

    private static IEnumerable<IEnumerable<int>> PermuteAll(IEnumerable<int> elements)
    {
        if (elements.Any())
        {
            foreach (var element in elements)
            {
                foreach (var perm in PermuteAll(elements.Where(elm => elm != element)))
                {
                    yield return perm.Prepend(element);
                }
            }
        }
        else
        {
            yield return Enumerable.Empty<int>();
        }
    }

    private static bool NextPermutationArray(int[] elements)
    {
        int i;
        for (i = elements.Length - 2; i >= 0; --i)
        {
            if (elements[i] < elements[i + 1]) break;
        }
        if (i < 0) return false;
        int j;
        for (j = elements.Length - 1; j >= 0; --j)
        {
            if (elements[j] > elements[i]) break;
        }
        (elements[i], elements[j]) = (elements[j], elements[i]);
        Array.Reverse(elements, i + 1, elements.Length - i - 1);
        return true;
    }

    private static bool NextPermutationSpan(Span<int> elements)
    {
        int i;
        for (i = elements.Length - 2; i >= 0; --i)
        {
            if (elements[i] < elements[i + 1]) break;
        }
        if (i < 0) return false;
        int j;
        for (j = elements.Length - 1; j >= 0; --j)
        {
            if (elements[j] > elements[i]) break;
        }
        (elements[i], elements[j]) = (elements[j], elements[i]);
        MemoryExtensions.Reverse(elements[(i + 1)..]);
        return true;
    }

    [Benchmark]
    public int PermuteAllAndCalcByLinq()
    {
        return PermuteAll(Enumerable.Range(0, n)).Select(perm =>
            {
                if (perm.Zip(perm.Skip(1)).Any(pair => dis[pair.First][pair.Second]))
                {
                    return int.MaxValue;
                }
                else
                {
                    return perm.Zip(Enumerable.Range(0, n)).Sum(pair => a[pair.First][pair.Second]);
                }
            }
        ).Min();
    }

    [Benchmark]
    public int PermuteAllAndCalcByFor()
    {
        int calcTime(int[] perm)
        {
            int t = 0;
            for (int i = 0; i < perm.Length; ++i)
            {
                if (i < perm.Length - 1 && dis[perm[i]][perm[i + 1]]) return int.MaxValue;
                t += a[perm[i]][i];
            }
            return t;
        }

        int min = int.MaxValue;
        foreach (var perm in PermuteAll(Enumerable.Range(0, n)))
        {
            int t = calcTime(perm.ToArray());
            if (t < min) min = t;
        }
        return min;
    }

    [Benchmark]
    public int NextPermutationArrayAndCalcByFor()
    {
        int calcTime(int[] perm)
        {
            int t = 0;
            for (int i = 0; i < perm.Length; ++i)
            {
                if (i < perm.Length - 1 && dis[perm[i]][perm[i + 1]]) return int.MaxValue;
                t += a[perm[i]][i];
            }
            return t;
        }

        int[] perm = Enumerable.Range(0, n).ToArray();
        int min = int.MaxValue;
        do
        {
            int t = calcTime(perm);
            if (t < min) min = t;
        } while (NextPermutationArray(perm));

        return min;
    }

    [Benchmark]
    public int NextPermutationArrayAndCalcByLinq()
    {
        int[] perm = Enumerable.Range(0, n).ToArray();
        int min = int.MaxValue;
        do
        {
            if(!perm.Zip(perm.Skip(1)).Any(pair => dis[pair.First][pair.Second]))
            {
                int t = perm.Zip(Enumerable.Range(0, n)).Sum(pair => a[pair.First][pair.Second]);
                if (t < min) min = t;
            }
        } while (NextPermutationArray(perm));

        return min;
    }

    [Benchmark]
    public int NextPermutationSpanAndCalcByFor()
    {
        int calcTime(Span<int> perm)
        {
            int t = 0;
            for (int i = 0; i < perm.Length; ++i)
            {
                if (i < perm.Length - 1 && dis[perm[i]][perm[i + 1]]) return int.MaxValue;
                t += a[perm[i]][i];
            }
            return t;
        }

        Span<int> perm = Enumerable.Range(0, n).ToArray();
        int min = int.MaxValue;
        do
        {
            int t = calcTime(perm);
            if (t < min) min = t;
        } while (NextPermutationSpan(perm));

        return min;
    }

    [Benchmark]
    public int NextPermutationSpanAndCalcByLinq()
    {
        int[] perm = Enumerable.Range(0, n).ToArray();
        int min = int.MaxValue;
        do
        {
            if(!perm.Zip(perm.Skip(1)).Any(pair => dis[pair.First][pair.Second]))
            {
                int t = perm.Zip(Enumerable.Range(0, n)).Sum(pair => a[pair.First][pair.Second]);
                if (t < min) min = t;
            }
        } while (NextPermutationSpan(perm));

        return min;
    }
}