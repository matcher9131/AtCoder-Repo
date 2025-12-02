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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<double> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<double> c(m), d(m);
    for (ll j = 0; j < m; ++j) {
        cin >> c[j] >> d[j];
    }

    auto isOK = [&](double x) -> bool {
        vector<double> cd(m);
        for (ll j = 0; j < m; ++j) {
            cd[j] = (c[j] + d[j]) * x - c[j];
        }
        sort(cd.begin(), cd.end());

        ll res = 0;
        for (ll i = 0; i < n; ++i) {
            double ab = a[i] - (a[i] + b[i]) * x;
            res += upper_bound(cd.begin(), cd.end(), ab) - cd.begin();
        }
        return res >= k;
    };

    double ok = 0;
    double ng = 1;
    for (ll i = 0; i < 60; ++i) {
        double mid = (ok+ng)/2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    cout << fixed << setprecision(15) << 100*ok << endl;

    return 0;
}