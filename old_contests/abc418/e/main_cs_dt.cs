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

Dictionary<(long x, long y), long> vec = new();
Dictionary<(long x, long y), long> midpoint = new();
for (int i = 0; i < n; ++i)
{
    for (int j = i + 1; j < n; ++j)
    {
        long dx = x[j] - x[i], dy = y[j] - y[i];
        if (dx == 0)
            vec[(0, 1)] = vec.GetValueOrDefault((0, 1)) + 1;
        else if (dy == 0)
            vec[(1, 0)] = vec.GetValueOrDefault((1, 0)) + 1;
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
            vec[(dx, dy)] = vec.GetValueOrDefault((dx, dy)) + 1;
        }

        midpoint[(x[i] + x[j], y[i] + y[j])] = midpoint.GetValueOrDefault((x[i] + x[j], y[i] + y[j])) + 1;
    }
}

long ans = 0;
foreach (var (_, c) in vec)
{
    ans += c * (c - 1) / 2;
}
foreach (var (_, c) in midpoint)
{
    ans -= c * (c - 1) / 2;
}
Console.WriteLine(ans);
