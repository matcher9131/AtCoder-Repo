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
    ll n, m;
    cin >> n >> m;
    vector<unordered_set<ll>> g(n);

    auto input = [&](ll from) -> void {
        ll k;
        cin >> k;
        for (ll i = 0; i < k; ++i) {
            ll vi;
            cin >> vi;
            --vi;
            g[from].insert(vi);
            g[vi].insert(from);
        }
    };

    vector<bool> visited(n);
    auto dfs = [&](auto dfs, ll from, ll parent) -> void {
        visited[from] = true;

        if (g[from].contains(n-1)) {
            cout << n << endl;
            string s;
            cin >> s;
            exit(0);
        }

        for (const ll to : g[from]) {
            if (visited[to]) continue;
            cout << to+1 << endl;
            input(to);
            dfs(dfs, to, from);
        }

        cout << parent+1 << endl;
        input(parent);
    };
    input(0);
    dfs(dfs, 0, -1);

    return 0;
}