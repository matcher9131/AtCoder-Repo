static long GCD(long x, long y)
{
    if (x == 0) return y;
    if (y == 0) return x;
    x = Math.Abs(x);
    y = Math.Abs(y);
    while (true)
    {
        if (x < y) (x, y) = (y, x);
        long r = x % y;
        if (r == 0) return y;
        x = y;
        y = r;
    }
}

int n = int.Parse(Console.ReadLine()!);
long[] x = new long[n];
long[] y = new long[n];
for (int i = 0; i < n; ++i)
{
    long[] point = Console.ReadLine()!.Split(' ').Select(long.Parse).ToArray();
    x[i] = point[0];
    y[i] = point[1];
}

Dictionary<long, Dictionary<long, long>> vec = new();
Dictionary<long, Dictionary<long, long>> midpoint = new();
for (int i = 0; i < n; ++i)
{
    for (int j = i + 1; j < n; ++j)
    {
        long dx = x[j] - x[i], dy = y[j] - y[i];
        if (dx == 0)
        {
            if (!vec.ContainsKey(0)) vec[0] = new();
            vec[0][1] = vec[0].GetValueOrDefault(1) + 1;
        }
        else if (dy == 0)
        {
            if (!vec.ContainsKey(1)) vec[1] = new();
            vec[1][0] = vec[1].GetValueOrDefault(0) + 1;
        }
        else
        {
            if (dx < 0)
            {
                dx = -dx;
                dy = -dy;
            }
            long g = GCD(dx, dy);
            dx /= g;
            dy /= g;
            if (!vec.ContainsKey(dx)) vec[dx] = new();
            vec[dx][dy] = vec[dx].GetValueOrDefault(dy) + 1;
        }

        long mx = x[i] + x[j], my = y[i] + y[j];
        if (!midpoint.ContainsKey(mx)) midpoint[mx] = new();
        midpoint[mx][my] = midpoint[mx].GetValueOrDefault(my) + 1;
    }
}

long ans = 0;
foreach (var (_, d) in vec)
{
    foreach (var (_, c) in d)
    {
        ans += c * (c - 1) / 2;
    }
}
foreach (var (_, d) in midpoint)
{
    foreach (var (_, c) in d)
    {
        ans -= c * (c - 1) / 2;
    }
}
Console.WriteLine(ans);
