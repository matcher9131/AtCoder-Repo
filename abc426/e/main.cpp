#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    double tsx, tsy, tgx, tgy;
    cin >> tsx >> tsy >> tgx >> tgy;
    double asx, asy, agx, agy;
    cin >> asx >> asy >> agx >> agy;
    double tl = sqrt((tgx-tsx)*(tgx-tsx) + (tgy-tsy)*(tgy-tsy));
    double al = sqrt((agx-asx)*(agx-asx) + (agy-asy)*(agy-asy));
    double tvx = (tgx-tsx)/tl;
    double tvy = (tgy-tsy)/tl;
    double avx = (agx-asx)/al;
    double avy = (agy-asy)/al;

    // printf("tl = %lf, tvx = %lf, tvy = %lf\n", tl, tvx, tvy);
    // printf("al = %lf, avx = %lf, avy = %lf\n", al, avx, avy);

    auto f = [&](double t) -> double {
        double tx = t > tl ? tgx : tsx + t*tvx;
        double ty = t > tl ? tgy : tsy + t*tvy;
        double ax = t > al ? agx : asx + t*avx;
        double ay = t > al ? agy : asy + t*avy;
        return sqrt((ax-tx)*(ax-tx) + (ay-ty)*(ay-ty));
    };

    double ans = min(f(0), f(max(tl, al)));
    {
        double left = 0;
        double right = min(tl, al);

        for (ll i = 0; i < 50; ++i) {
            double ml = (2*left+right)/3;
            double mr = (left+2*right)/3;
            double f1 = f(ml);
            double f2 = f(mr);
            if (f1 < f2) right = mr;
            else left = ml;
        }
        chmin(ans, f(left));
    }
    {
        double left = min(tl, al);
        double right = max(tl, al);

        for (ll i = 0; i < 50; ++i) {
            double ml = (2*left+right)/3;
            double mr = (left+2*right)/3;
            double f1 = f(ml);
            double f2 = f(mr);
            if (f1 < f2) right = mr;
            else left = ml;
        }
        chmin(ans, f(left));
    }
    
    cout << fixed << setprecision(15) << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}

// 1079ms
