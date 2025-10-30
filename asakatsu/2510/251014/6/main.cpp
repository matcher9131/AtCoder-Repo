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
    vector<vector<ll>> g(n);
    for (ll i = 1; i < n; ++i) {
        ll x;
        cin >> x;
        --x;
        g[x].push_back(i);
    }

    vector<bool> visited(n);
    vector<ll> dist(n, INF);
    auto dfs = [&](auto dfs, ll from) -> ll {
        visited[from] = true;
        vector<ll> children;
        for (const ll to : g[from]) {
            if (visited[to]) continue;
            children.push_back(dfs(dfs, to));
        }

        if (children.empty()) return 0;
        sort(children.begin(), children.end(), greater<>());
        ll res = 0;
        for (ll i = 0; i < (ll)children.size(); ++i) {
            chmax(res, children[i] + i + 1);
        }
        return res;
    };

    cout << dfs(dfs, 0) << endl;

    return 0;
}