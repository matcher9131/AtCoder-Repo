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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for (ll i = 0; i < k; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<double> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    for (ll i = 0; i < n; ++i) {
        double cur = INF;
        for (const ll ai : a) {
            double dx = x[ai] - x[i];
            double dy = y[ai] - y[i];
            chmin(cur, sqrt(dx*dx + dy*dy));
        }
        chmax(ans, cur);
    }
    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}