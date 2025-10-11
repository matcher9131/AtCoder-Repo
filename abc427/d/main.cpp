#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
    }

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2*k+1, vector<ll>(2)));
    auto dfs = [&](auto f, ll from, ll rest, ll turn) -> ll {
        if (dp[from][rest][turn] != 0) return dp[from][rest][turn];
        if (rest == 0) return turn == 0 ? s[from] == 'A' ? 1 : -1 : s[from] == 'B' ? 1 : -1;

        ll res = -INF;
        for (const auto to : g[from]) {
            ll score = -f(f, to, rest-1, !turn);
            chmax(res, score);
        }
        return dp[from][rest][turn] = res;
    };
    ll ans = dfs(dfs, 0, 2*k, 0);

    cout << (ans == 1 ? "Alice" : "Bob") << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}