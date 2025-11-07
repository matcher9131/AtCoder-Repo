#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, m;
    cin >> n >> m;
    vector<bool> danger(n+1);
    for (ll i = 0; i < m; ++i) {
        ll ai;
        cin >> ai;
        danger[ai] = true;
    }

    vector<mint> dp(n+1);
    dp[0] = 1;
    for (ll i = 0; i < n; ++i) {
        if (!danger[i+1]) dp[i+1] += dp[i];
        if (i+2 <= n && !danger[i+2]) dp[i+2] += dp[i];
    }
    cout << dp[n].val() << endl;

    return 0;
}