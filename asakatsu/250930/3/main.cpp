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
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(2, -INF));
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        if (dp[i][0] != -INF) {
            chmax(dp[i+1][0], dp[i][0]);
            chmax(dp[i+1][x[i]], dp[i][0] + y[i]);
        }
        if (dp[i][1] != -INF) {
            chmax(dp[i+1][1], dp[i][1]);
            if (!x[i]) chmax(dp[i+1][0], dp[i][1] + y[i]);
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}