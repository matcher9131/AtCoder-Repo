#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    vector<ll> color(n, -1);
    function<void(ll, ll)> dfs = [&](ll from, ll c) -> void {
        color[from] = c;
        for (const auto &[to, w] : g[from]) {
            if (color[to] >= 0) continue;
            dfs(to, w%2 ? !c : c);
        }
    };
    dfs(0, 0);

    for (ll i = 0; i < n; ++i) {
        cout << color[i] << endl;
    }

    return 0;
}