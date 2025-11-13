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
    vector<string> g(n);
    for (ll i = 0; i < n; ++i) {
        cin >> g[i];
    }

    vector<vector<ll>> s(n+1, vector<ll>(n+1));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + (g[i][j] == 'B');
        }
    }

    while (nq--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ++c;
        ++d;
        ll qa = a/n, qb = b/n, qc = c/n, qd = d/n;
        ll ra = a%n, rb = b%n, rc = c%n, rd = d%n;
        ll ans = (qc - qa) * (qd - qb) * s[n][n];
        ans -= (qd - qb) * s[ra][n];
        ans -= (qc - qa) * s[n][rb];
        ans += s[ra][rb];
        ans += (qd - qb) * s[rc][n];
        ans -= s[rc][rb];
        ans += (qc - qa) * s[n][rd];
        ans -= s[ra][rd];
        ans += s[rc][rd];
        cout << ans << "\n";
    }

    return 0;
}