int n = int.Parse(Console.ReadLine()!);
long[][] a = new long[n][];
for (long i = 0; i < n; ++i)
{
    a[i] = Console.ReadLine()!.Split(' ').Select(long.Parse).ToArray();
}

Dictionary<long, long>[] former = new Dictionary<long, long>[n];
for (int i = 0; i < n; ++i) former[i] = new();
for (ulong bit = 0; bit < (1UL << (n-1)); ++bit)
{
    long x = a[0][0], i = 0, j = 0;
    for (int bi = 0; bi < n-1; ++bi)
    {
        if ((bit & (1UL << bi)) > 0) ++j;
        else ++i;
        x ^= a[i][j];
    }
    former[i][x] = former[i].GetValueOrDefault(x) + 1;
}

Dictionary<long, long>[] latter = new Dictionary<long, long>[n];
for (int i = 0; i < n; ++i) latter[i] = new();
for (ulong bit = 0; bit < (1UL << (n-1)); ++bit)
{
    long x = a[n-1][n-1], i = n-1, j = n-1;
    for (int bi = 0; bi < n-1; ++bi)
    {
        if ((bit & (1UL << bi)) > 0) --j;
        else --i;
        x ^= a[i][j];
    }
    x ^= a[i][j];
    latter[i][x] = latter[i].GetValueOrDefault(x) + 1;
}

long ans = 0;
for (int i = 0; i < n; ++i)
{
    foreach (var (x, c) in former[i])
    {
        ans += c * latter[i].GetValueOrDefault(x);
    }
}

Console.WriteLine(ans);

// 312ms
