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
    map<double, ll> x, y;
    ll cSum = 0;
    for (ll i = 0; i < n; ++i) {
        ll xi, yi, ci;
        cin >> xi >> yi >> ci;
        x[xi] += ci;
        y[yi] += ci;
        cSum += ci;
    }

    auto f = [&](map<double, ll> &x) -> double {
        ll cPrev = -cSum;
        double xPrev = -1e5;
        for (const auto &[xi, ci] : x) {
            ll cCur = cPrev + 2 * ci;
            if (cCur > 0) return cPrev < 0 ? xi : (xPrev + xi) / 2;
            cPrev = cCur;
            xPrev = xi;
        }
        return INF;
    };

    cout << fixed << setprecision(15) << max(f(x), f(y)) << endl;

    return 0;
}