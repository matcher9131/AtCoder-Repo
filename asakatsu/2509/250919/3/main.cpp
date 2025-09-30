#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(n, -1));
    for (ll i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }

    for (ll bit = 0; bit < 1LL<<n; ++bit) {
        for (ll from = 0; from < n; ++from) {
            if (dp[bit][from] == -1) continue;
            for (const auto &[to, w] : g[from]) {
                ll newBit = bit | (1LL << to);
                if (newBit == bit) continue;
                dp[newBit][to] = max(dp[newBit][to], dp[bit][from] + w);
            }
        }
    }

    ll ans = 0;
    for (ll bit = 0; bit < 1LL<<n; ++bit) {
        for (ll i = 0; i < n; ++i) {
            ans = max(ans, dp[bit][i]);
        }
    }
    cout << ans << endl;

    return 0;
}