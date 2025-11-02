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
    ll n, nq;
    cin >> n >> nq;
    vector<double> x(n), r(n), h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> r[i] >> h[i];
    }

    vector<double> v(n);
    for (ll i = 0; i < n; ++i) {
        v[i] = r[i] * r[i] * acos(-1) * h[i] / 3.0;
    }

    cout << fixed << setprecision(15);
    while (nq--) {
        double l, r;
        cin >> l >> r;

        double ans = 0;
        for (ll i = 0; i < n; ++i) {
            if (x[i]+h[i] < l || r < x[i]) continue;
            double hi = min(x[i] + h[i] - l, h[i]);
            double ratio = hi / h[i];
            double vi = v[i] * ratio * ratio * ratio;
            double exh = max(x[i] + h[i] - r, 0.0);
            double exr = exh / h[i];
            double exv = v[i] * exr * exr * exr;
            ans += vi - exv;
        }
        cout << ans << "\n";
    }

    return 0;
}