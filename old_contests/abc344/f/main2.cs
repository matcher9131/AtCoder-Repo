long n = long.Parse(Console.ReadLine()!);
long[][] p = new long[n][];
long[][] r = new long[n][];
long[][] d = new long[n-1][];
for (long i = 0; i < p.Length; ++i)
{
    p[i] = Console.ReadLine()!.Split(" ").Select(long.Parse).ToArray();
}
for (long i = 0; i < r.Length; ++i)
{
    r[i] = Console.ReadLine()!.Split(" ").Select(long.Parse).ToArray();
}
for (long i = 0; i < d.Length; ++i)
{
    d[i] = Console.ReadLine()!.Split(" ").Select(long.Parse).ToArray();
}

Dictionary<long, (long count, long possession)>[][] dp = new Dictionary<long, (long count, long possession)>[n][];
for (long i = 0; i < dp.Length; ++i)
{
    dp[i] = new Dictionary<long, (long count, long possession)>[n];
    for (long j = 0; j < dp[i].Length; ++j)
    {
        dp[i][j] = new();
    }
}
dp[0][0][p[0][0]] = (0, 0);

void Update(long i, long j, long k, (long count, long possession) newValue)
{
    if (dp[i][j].ContainsKey(k))
    {
        if (newValue.count < dp[i][j][k].count || (newValue.count == dp[i][j][k].count && newValue.possession > dp[i][j][k].possession))
        {
            dp[i][j][k] = newValue;
        }
    }
    else
    {
        dp[i][j][k] = newValue;
    }
}

for (long i = 0; i < dp.Length; ++i)
{
    for (long j = 0; j < dp[i].Length; ++j)
    {
        foreach (var (pMax, val) in dp[i][j])
        {
            var (count, possession) = val;
            if (i < d.Length)
            {
                long remain = possession >= d[i][j] ? 0 : (d[i][j] - possession + pMax - 1) / pMax;
                long newPossession = possession + remain * pMax - d[i][j];
                Update(i + 1, j, Math.Max(pMax, p[i + 1][j]), (count + remain + 1, newPossession));
            }
            if (j < r[i].Length)
            {
                long remain = possession >= r[i][j] ? 0 : (r[i][j] - possession + pMax - 1) / pMax;
                long newPossession = possession + remain * pMax - r[i][j];
                Update(i, j + 1, Math.Max(pMax, p[i][j + 1]), (count + remain + 1, newPossession));
            }
        }
    }
}

long ans = (long)1e18;
foreach (var (_, val) in dp[n - 1][n - 1])
{
    if (val.count < ans) ans = val.count;
}

Console.WriteLine(ans);

// 1315ms
