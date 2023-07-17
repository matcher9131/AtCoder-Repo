using System;
using System.Linq;

namespace Typical90_032
{
    public static class Answer3
    {
        private static bool NextPermutation(int[] elements)
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

            int[] perm = Enumerable.Range(0, n).ToArray();

            int calcTime(int[] perm)
            {
                int t = 0;
                for (int i = 0; i < perm.Length; ++i)
                {
                    if (i < perm.Length - 1 && dis[perm[i], perm[i + 1]]) return int.MaxValue;
                    t += a[perm[i]][i];
                }
                return t;
            }

            int min = int.MaxValue;
            do
            {
                int t = calcTime(perm);
                if (t < min) min = t;
            }
            while (NextPermutation(perm));

            Console.WriteLine(min == int.MaxValue ? -1 : min);
        }
    }
}