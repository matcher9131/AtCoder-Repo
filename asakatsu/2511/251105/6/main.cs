static decimal Sqrt(decimal x, decimal epsilon = 0.00000000000001m)
{
    if (x == 0) return 0;
    decimal res = x / 2;
    while (Math.Abs(res * res - x) > epsilon)
    {
        res = (res + x / res) / 2;
    }
    return res;
}

decimal[] vars = Console.ReadLine().Split().Select(decimal.Parse).ToArray();
decimal x0 = vars[0];
decimal y0 = vars[1];
decimal r = vars[2];

decimal left = Math.Ceiling(x0 - r);
decimal right = Math.Floor(x0 + r);

long ans = 0;
for (decimal x = left; x <= right; ++x)
{
    decimal dx = x - x0;
    decimal dy = Sqrt(r * r - dx * dx);
    decimal bottom = Math.Ceiling(y0 - dy);
    decimal top = Math.Floor(y0 + dy);
    ans += (int)(top - bottom) + 1;
}
Console.WriteLine(ans);