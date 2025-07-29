#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    vector<vector<ll>> g(n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            if ((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) <= d * d) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n);
    function<void(int)> dfs = [&](int from) -> void {
        visited[from] = true;
        for (const auto to : g[from]) {
            if (visited[to]) continue;
            dfs(to);
        }
    };
    dfs(0);

    for (ll i = 0; i < n; ++i) {
        cout << (visited[i] ? "Yes" : "No") << endl;
    }

    return 0;
}