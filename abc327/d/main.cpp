#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<ll> b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
        --b[i];
    }
    
    vector<vector<int>> g(n);
    for (ll i = 0; i < m; ++i) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    vector<int> color(n);
    function<bool(int, int, int)> dfs = [&](int from, int parent, int c) -> bool {
        color[from] = c;
        for (const int to : g[from]) {
            if (to == parent) continue;
            if (color[to] == c) return true;
            if (color[to] == 0) {
                bool result = dfs(to, from, -c);
                if (result) return true;
            }
        }
        return false;
    };

    for (ll i = 0; i < n; ++i) {
        if (color[i] == 0) {
            bool result = dfs(i, -1, 1);
            if (result) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}