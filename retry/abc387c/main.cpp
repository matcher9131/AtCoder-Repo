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
    ll l, r;
    cin >> l >> r;

    auto g = [](ll n) -> ll {
        ll res = 0;
        for (ll ini = 1; ini < 10; ++ini) {
            ll cur = 1;
            for (ll i = 0; i < n-1; ++i) {
                cur *= ini;
            }
            res += cur;
        }
        return res;
    };

    auto f = [&](ll x) -> ll {
        if (x == 0) return 0;

        string s = to_string(x);
        ll n = s.size();
        ll res = 0;
        for (ll i = 1; i < n; ++i) {
            res += g(i);
        }

        vector<vector<vector<ll>>> dp(10, vector<vector<ll>>(n, vector<ll>(2)));
        for (ll i = 1; i < s[0] - '0'; ++i) {
            dp[i][0][0] = 1;
        }
        dp[s[0] - '0'][0][1] = 1;
        
        for (ll i = 1; i < n; ++i) {
            for (ll ini = 1; ini < 10; ++ini) {
                dp[ini][i][0] = ini * dp[ini][i-1][0] + min(ini, (ll)(s[i] - '0')) * dp[ini][i-1][1];
                if (ini > s[i] - '0') dp[ini][i][1] = dp[ini][i-1][1];
            }
        }

        for (ll ini = 1; ini < 10; ++ini) {
            res += dp[ini][n-1][0];
            res += dp[ini][n-1][1];
        }
        return res;
    };

    cout << f(r) - f(l-1) << endl;

    return 0;
}