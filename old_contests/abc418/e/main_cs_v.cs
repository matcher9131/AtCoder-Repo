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

(long x, long y)[] vec = new (long x, long y)[n * (n - 1) / 2];
(long x, long y)[] midpoint = new (long x, long y)[n * (n - 1) / 2];
int arrayIndex = 0;
for (int i = 0; i < n; ++i)
{
    for (int j = i + 1; j < n; ++j)
    {
        long dx = x[j] - x[i], dy = y[j] - y[i];
        if (dx == 0)
            vec[arrayIndex] = (0, 1);
        else if (dy == 0)
            vec[arrayIndex] = (1, 0);
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
            vec[arrayIndex] = (dx, dy);
        }

        midpoint[arrayIndex] = (x[i] + x[j], y[i] + y[j]);
        ++arrayIndex;
    }
}
Array.Sort(vec);
Array.Sort(midpoint);

long count((long x, long y)[] v)
{
    long res = 0;
    int left = 0;
    while (left < v.Length)
    {
        int right = left;
        while (right < v.Length && v[right] == v[left]) ++right;
        res += (right - left) * (right - left - 1) / 2;
        left = right;
    }
    return res;
}

Console.WriteLine(count(vec) - count(midpoint));
