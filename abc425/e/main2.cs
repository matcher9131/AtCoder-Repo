long PowMod(long x, long n, long m)
{
    if (!(x >= 0 && m >= 1)) throw new ArgumentOutOfRangeException();
    long res = 1;
    x %= m;
    while (n > 0)
    {
        if ((n & 1L) == 1L)
        {
            res = res * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

string[] input0 = Console.ReadLine()!.Split(" ");
long t = long.Parse(input0[0]);
long m = long.Parse(input0[1]);

var isPrime = new bool[5001];
Array.Fill(isPrime, true);
var minFactor = new long[5001];
Array.Fill(minFactor, -1);
isPrime[1] = false;
minFactor[1] = 1;
for (long p = 2; p < isPrime.Length; ++p)
{
    if (!isPrime[p]) continue;
    minFactor[p] = p;
    for (long q = 2 * p; q < isPrime.Length; q += p)
    {
        isPrime[q] = false;
        if (minFactor[q] == -1) minFactor[q] = p;
    }
}

var factorized = new Dictionary<long, long>[5001];
factorized[1] = new();
for (long x = 2; x < factorized.Length; ++x)
{
    factorized[x] = new(factorized[x - 1]);
    long y = x;
    while (y > 1)
    {
        long p = minFactor[y];
        while (minFactor[y] == p)
        {
            y /= p;
            factorized[x][p] = factorized[x].GetValueOrDefault(p) + 1;
        }
    }
}

while (t-- > 0)
{
    long n = long.Parse(Console.ReadLine()!);
    long[] c = Console.ReadLine()!.Split(" ").Select(long.Parse).ToArray();
    long s = 0;
    foreach (long ci in c) s += ci;

    Dictionary<long, long> fact = new(factorized[s]);
    foreach (long ci in c)
    {
        foreach (var (p, cnt) in factorized[ci])
        {
            fact[p] -= cnt;
        }
    }

    long ans = 1;
    foreach (var (p, cnt) in fact)
    {
        ans = ans * PowMod(p, cnt, m) % m;
    }
    Console.WriteLine(ans);
}

// TLE(17/51)
