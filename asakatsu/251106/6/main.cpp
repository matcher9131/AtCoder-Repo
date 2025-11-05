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
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<mint>> dp(n, vector<mint>(2));
    auto dfs = [&](auto dfs, ll from, ll parent) -> void {
        for (const ll to : g[from]) {
            if (to == parent) continue;
            dfs(dfs, to, from);
        }
        dp[from][0] = 1;
        dp[from][1] = 1;
        for (const ll to : g[from]) {
            if (to == parent) continue;
            dp[from][0] *= dp[to][0] + dp[to][1];
            dp[from][1] *= dp[to][0];
        }
    };
    dfs(dfs, 0, -1);

    cout << (dp[0][0] + dp[0][1]).val() << endl;

    return 0;
}