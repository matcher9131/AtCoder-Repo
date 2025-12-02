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
    vector<double> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    double px = 0, py = 0;
    for (ll i = 0; i < n; ++i) {
        double dx = x[i] - px;
        double dy = y[i] - py;
        ans += sqrt(dx*dx + dy*dy);
        px = x[i];
        py = y[i];
    }
    ans += sqrt(px*px + py*py);
    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}