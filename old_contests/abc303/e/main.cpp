#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<unordered_set<ll>> g(n);
    vector<ll> deg(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
        ++deg[a];
        ++deg[b];
    }

    vector<bool> used(n);
    vector<ll> ans;
    queue<ll> leaf;
    for (ll i = 0; i < n; ++i) {
        if (deg[i] == 1) leaf.push(i);
    }
    while (!leaf.empty()) {
        ll v = leaf.front();
        leaf.pop();
        if (used[v]) continue;
        ll center = *g[v].begin();
        used[center] = true;
        ans.push_back((ll)g[center].size());
        for (const ll child : g[center]) {
            used[child] = true;
            for (const ll next : g[child]) {
                if (next == center) continue;
                g[next].erase(child);
                if ((ll)g[next].size() == 1) leaf.push(next);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}