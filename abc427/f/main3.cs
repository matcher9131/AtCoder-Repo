long[] input0 = Console.ReadLine()!.Split(" ").Select(long.Parse).ToArray();
long n = input0[0];
long m = input0[1];
long[] a = Console.ReadLine()!.Split(" ").Select(long.Parse).ToArray();

Dictionary<long, long>[] fMap = Enumerable.Range(0, 2).Select(_ => new Dictionary<long, long>()).ToArray();
void dfs(long last, long cur)
{
    long j = last == n / 2 - 1 ? 1 : 0;
    long k = cur % m;
    if (!fMap[j].ContainsKey(k)) fMap[j][k] = 0;
    ++fMap[j][k];
    for (long i = last + 2; i < n / 2; ++i)
    {
        dfs(i, cur + a[i]);
    }
}
dfs(-2, 0);

Dictionary<long, long>[] lMap = Enumerable.Range(0, 2).Select(_ => new Dictionary<long, long>()).ToArray();
void dfs2(long last, long cur, bool containsFirst)
{
    long j = containsFirst ? 1 : 0;
    long k = cur % m;
    if (!lMap[j].ContainsKey(k)) lMap[j][k] = 0;
    ++lMap[j][k];
    for (long i = last + 2; i < n; ++i)
    {
        dfs2(i, cur + a[i], containsFirst || i == n / 2);
    }
}
dfs2(n / 2 - 2, 0, false);

long ans = 0;
foreach (var (r, c) in fMap[0])
{
    long rr = r == 0 ? 0 : m - r;
    ans += c * (lMap[0].GetValueOrDefault(rr) + lMap[1].GetValueOrDefault(rr));
}
foreach (var (r, c) in fMap[1])
{
    long rr = r == 0 ? 0 : m - r;
    ans += c * lMap[0].GetValueOrDefault(rr);
}

Console.WriteLine(ans);
