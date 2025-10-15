static void Solve()
{
    double[] takahashi = Console.ReadLine()!.Split(' ').Select(double.Parse).ToArray();
    double tsx = takahashi[0], tsy = takahashi[1], tgx = takahashi[2], tgy = takahashi[3];
    double[] aoki = Console.ReadLine()!.Split(' ').Select(double.Parse).ToArray();
    double asx = aoki[0], asy = aoki[1], agx = aoki[2], agy = aoki[3];
    double tl = Math.Sqrt((tgx - tsx) * (tgx - tsx) + (tgy - tsy) * (tgy - tsy));
    double al = Math.Sqrt((agx - asx) * (agx - asx) + (agy - asy) * (agy - asy));
    double tvx = (tgx - tsx) / tl;
    double tvy = (tgy - tsy) / tl;
    double avx = (agx - asx) / al;
    double avy = (agy - asy) / al;

    double f(double t)
    {
        double tx = t > tl ? tgx : tsx + t * tvx;
        double ty = t > tl ? tgy : tsy + t * tvy;
        double ax = t > al ? agx : asx + t * avx;
        double ay = t > al ? agy : asy + t * avy;
        return Math.Sqrt((ax - tx) * (ax - tx) + (ay - ty) * (ay - ty));
    }

    double ans = Math.Min(f(0), f(Math.Max(tl, al)));
    {
        double left = 0;
        double right = Math.Min(tl, al);

        for (int i = 0; i < 50; ++i)
        {
            double ml = (2 * left + right) / 3;
            double mr = (left + 2 * right) / 3;
            double f1 = f(ml);
            double f2 = f(mr);
            if (f1 < f2) right = mr;
            else left = ml;
        }
        double fl = f(left);
        if (fl < ans) ans = fl;
    }
    {
        double left = Math.Min(tl, al);
        double right = Math.Max(tl, al);

        for (int i = 0; i < 50; ++i)
        {
            double ml = (2 * left + right) / 3;
            double mr = (left + 2 * right) / 3;
            double f1 = f(ml);
            double f2 = f(mr);
            if (f1 < f2) right = mr;
            else left = ml;
        }
        double fl = f(left);
        if (fl < ans) ans = fl;
    }

    Console.WriteLine(ans.ToString("F15"));
}

int t = int.Parse(Console.ReadLine()!);
while (t-- > 0) Solve();

// 941ms
