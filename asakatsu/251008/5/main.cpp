#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<double> x(n), y(n), c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> c[i];
    }
    
    auto f = [&](vector<double> &x, double x0) -> double {
        double res = 0;
        for (ll i = 0; i < n; ++i) {
            chmax(res, c[i] * abs(x[i] - x0));
        }
        return res;
    };

    double xl = -1e5, xr = 1e5, yl = -1e5, yr = 1e5;
    for (ll i = 0; i < 100; ++i) {
        double x1 = (2*xl + xr) / 3;
        double x2 = (xl + 2*xr) / 3;
        if (f(x, x1) < f(x, x2)) xr = x2;
        else xl = x1;
        double y1 = (2*yl + yr) / 3;
        double y2 = (yl + 2*yr) / 3;
        if (f(y, y1) < f(y, y2)) yr = y2;
        else yl = y1;
    }

    cout << fixed << setprecision(15) << max(f(x, xl), f(y, yl)) << endl;

    return 0;
}