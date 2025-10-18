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
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
    }

    vector<bool> pre(n), post(n);
    vector<ll> history;
    auto dfs = [&](auto dfs, ll from) -> ll {
        pre[from] = true;
        history.push_back(from);
        for (const ll to : g[from]) {
            if (post[to]) continue;
            if (pre[to] && !post[to]) {
                return to;
            }

            ll start = dfs(dfs, to);
            if (start != -1) return start;
        }
        post[from] = true;
        history.pop_back();
        return -1;
    };

    ll start = -1;
    for (ll i = 0; i < n && start == -1; ++i) {
        if (pre[i]) continue;
        history.clear();
        start = dfs(dfs, i);
        if (start != -1) {
            vector<ll> ans;
            while (!history.empty()) {
                ll to = history.back();
                ans.push_back(to);
                history.pop_back();
                if (to == start) break;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (const ll v : ans) cout << v+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}