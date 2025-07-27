#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    ll ansSum = accumulate(c.begin(), c.end() - 1, 0LL);

    vector<ll> ans(n);
    vector<pair<ll, ll>> depth(n, {-1, 0});
    function<void(int, int)> dfs = [&](int from, int d) {
        depth[from] = {d, from};
        for (const ll to : g[from]) {
            if (depth[to].first != -1) continue;
            dfs(to, d+1);
        }
    };
    dfs(0, 0);
    sort(depth.begin(), depth.end(), greater<>());

    for (ll i = 0; i < n; ++i) {
        int v = depth[i].second;
        ans[v] = c[i];
    }

    cout << ansSum << endl;
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }
    return 0;
}