#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
    }

    vector<bool> visited(n);
    vector<ll> order;
    function<void(ll)> dfs = [&](ll from) {
        visited[from] = true;
        for (const ll to : g[from]) {
            if (visited[to]) continue;
            dfs(to);
        }
        order.push_back(from);
    };
    for (ll i = 0; i < n; ++i) {
        if (visited[i]) continue;
        dfs(i);
    }
    reverse(order.begin(), order.end());

    vector<ll> dp(n);
    for (ll i = 0; i < n; ++i) {
        ll from = order[i];
        for (const ll to : g[from]) {
            dp[to] = max(dp[to], dp[from] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}