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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n), c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    ll m = 10*n;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(m+1, vector<ll>(m+1, INF)));
    dp[0][0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll xi = 0; xi <= m; ++xi) {
            for (ll yi = 0; yi <= m; ++yi) {
                if (dp[i][xi][yi] == INF) continue;
                chmin(dp[i+1][xi][yi], dp[i][xi][yi]);
                if (xi+a[i] <= m && yi+b[i] <= m) chmin(dp[i+1][xi+a[i]][yi+b[i]], dp[i][xi][yi] + c[i]);
            }
        }
    }

    ll ans = INF;
    for (ll xi = 1; xi <= m; ++xi) {
        for (ll yi = 1; yi <= m; ++yi) {
            if (xi*y != yi*x) continue;
            chmin(ans, dp[n][xi][yi]);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}