namespace Typical90_032
{
    public static class Answer4
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
            foreach (var perm in PermuteAll(Enumerable.Range(0, n)))
            {
                int t = calcTime(perm.ToArray());
                if (t < min) min = t;
            }

            Console.WriteLine(min == int.MaxValue ? -1 : min);
        }
    }
}