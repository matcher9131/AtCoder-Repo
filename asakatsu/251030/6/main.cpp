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
    vector<ll> d(n);
    for (ll i = 0; i < n; ++i) {
        cin >> d[i];
    }
    vector<ll> l(2), c(2), k(2);
    for (ll i = 0; i < 2; ++i) {
        cin >> l[i] >> c[i] >> k[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(k[0]+1, INF));
    fill(dp[0].begin(), dp[0].end(), 0);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= k[0]; ++j) {
            for (ll j1 = 0; j1 <= k[0]-j; ++j1) {
                ll rest = d[i] - j1*l[0];
                if (rest < 0) rest = 0;
                chmin(dp[i+1][j+j1], dp[i][j] + (rest + l[1]-1) / l[1]);
            }
        }
    }

    ll ans = INF;
    for (ll j = 0; j <= k[0]; ++j) {
        if (dp[n][j] <= k[1]) chmin(ans, j*c[0] + dp[n][j]*c[1]);
    }
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}