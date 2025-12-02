#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/scc>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, m;
    cin >> n >> m;
    atcoder::scc_graph g(n);
    vector<vector<ll>> g2(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g.add_edge(a, b);
        g2[a].push_back(b);
    }

    auto groups = g.scc();
    ll k = groups.size();
    vector<ll> revGroup(n);
    for (ll gi = 0; gi < k; ++gi) {
        for (const ll v : groups[gi]) {
            revGroup[v] = gi;
        }
    }
    
    vector<bool> dp(k);
    ll ans = 0;
    for (ll gi = k - 1; gi >= 0; --gi) {
        if (groups[gi].size() > 1) {
            dp[gi] = true;
        } else {
            for (const ll to : g2[groups[gi][0]]) {
                dp[gi] = dp[gi] || dp[revGroup[to]];
            }
        }
        if (dp[gi]) ans += groups[gi].size();
    }
    cout << ans << endl;

    return 0;
}