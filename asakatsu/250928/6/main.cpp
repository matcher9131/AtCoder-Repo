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
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    vector<ll> dp1(n); // d_i本以下を選ぶときの最大値
    vector<ll> dp2(n); // d_i本未満を選ぶときの最大値

    auto dfs = [&](auto f, ll from, ll parent) -> void {
        vector<ll> diff;
        for (const auto &[to, w] : g[from]) {
            if (to == parent) continue;
            f(f, to, from);
            dp1[from] += dp1[to];
            dp2[from] += dp1[to];
            diff.push_back(dp2[to] + w - dp1[to]);
        }
        sort(diff.begin(), diff.end(), greater<>());

        for (ll i = 0; i < d[from] && i < (ll)diff.size() && diff[i] > 0; ++i) {
            dp1[from] += diff[i];
        }
        for (ll i = 0; i < d[from]-1 && i < (ll)diff.size() && diff[i] > 0; ++i) {
            dp2[from] += diff[i];
        }
        if (d[from] == 0) dp2[from] = -INF;
    };
    dfs(dfs, 0, -1);

    cout << dp1[0] << endl;

    return 0;
}