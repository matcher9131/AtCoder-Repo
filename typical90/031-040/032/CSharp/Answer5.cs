using System;
using System.Collections.Generic;
using System.Linq;

namespace Typical90_032
{
    public static class Answer5
    {
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

        public static void Run()
        {
            int n = int.Parse(Console.ReadLine()!);
            int[][] a = new int[n][];
            for (int i = 0; i < n; i++)
            {
                a[i] = Console.ReadLine()!.Split().Select(int.Parse).ToArray();
            }
            int m = int.Parse(Console.ReadLine()!);
            bool[,] dis = new bool[n, n];
            for (int i = 0; i < m; ++i)
            {
                var tmp = Console.ReadLine()!.Split().Select(s => int.Parse(s) - 1).ToArray();
                dis[tmp[0], tmp[1]] = true;
                dis[tmp[1], tmp[0]] = true;
            }

            int min = PermuteAll(Enumerable.Range(0, n)).AsParallel().Select(perm =>
                {
                    if (perm.Zip(perm.Skip(1)).All(pair => !dis[pair.First, pair.Second]))
                    {
                        return perm.Zip(Enumerable.Range(0, n)).Sum(pair => a[pair.First][pair.Second]);
                    }
                    else
                    {
                        return int.MaxValue;
                    }
                }
            ).Min();

            Console.WriteLine(min == int.MaxValue ? -1 : min);
        }
    }
}