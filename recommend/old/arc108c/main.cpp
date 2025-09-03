#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

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

    vector<ll> ans(n, -1);
    function<void(int, int)> dfs = [&](int from, int num) -> void {
        ans[from] = num;
        for (const auto &[to, w] : g[from]) {
            if (ans[to] != -1) continue;
            ll nextNum = ans[from] == w
                ? (w == 1 ? 2 : 1)
                : w;
            dfs(to, nextNum);
        }
    };
    dfs(0, 1);

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}