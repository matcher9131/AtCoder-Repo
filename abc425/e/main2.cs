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

Span<bool> isPrime = new bool[5001];
for (int i = 0; i < isPrime.Length; ++i) isPrime[i] = true;
Span<int> minFactor = new int[5001];
for (int i = 0; i < minFactor.Length; ++i) minFactor[i] = -1;
isPrime[1] = false;
minFactor[1] = 1;
for (int p = 2; p < isPrime.Length; ++p)
{
    if (!isPrime[p]) continue;
    minFactor[p] = p;
    for (int q = 2 * p; q < isPrime.Length; q += p)
    {
        isPrime[q] = false;
        if (minFactor[q] == -1) minFactor[q] = p;
    }
}

Span<Dictionary<int, int>> factorized = new Dictionary<int, int>[5001];
factorized[1] = new();
for (int x = 2; x < factorized.Length; ++x)
{
    factorized[x] = new(factorized[x - 1]);
    int y = x;
    while (y > 1)
    {
        int p = minFactor[y];
        while (minFactor[y] == p)
        {
            y /= p;
            factorized[x][p] = factorized[x].GetValueOrDefault(p) + 1;
        }
    }
}

while (t-- > 0)
{
    int n = int.Parse(Console.ReadLine()!);
    int[] c = Console.ReadLine()!.Split(" ").Select(int.Parse).ToArray();
    int s = 0;
    foreach (int ci in c) s += ci;

    Dictionary<int, int> fact = new(factorized[s]);
    foreach (int ci in c)
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
