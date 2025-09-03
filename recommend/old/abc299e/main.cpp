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
        g[b].push_back(a);
    }

    ll k;
    cin >> k;
    vector<ll> p(k), d(k);
    for (ll i = 0; i < k; ++i) {
        cin >> p[i] >> d[i];
        --p[i];
    }

    string ans(n, '1');
    vector<unordered_set<ll>> blackGroup(k);
    for (ll ki = 0; ki < k; ++ki) {
        if (d[ki] == 0) {
            blackGroup[ki].insert(p[ki]);
            continue;
        }

        vector<ll> dist(n, INF);
        dist[p[ki]] = 0;
        queue<ll> que;
        que.push(p[ki]);
        while (!que.empty()) {
            ll v = que.front();
            que.pop();
            if (dist[v] < d[ki]) ans[v] = '0';
            else if (dist[v] == d[ki]) {
                blackGroup[ki].insert(v);
                continue;
            } else continue;
            for (const ll nv : g[v]) {
                if (dist[nv] < INF) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    for (const auto &s : blackGroup) {
        if (all_of(s.begin(), s.end(), [&](ll v) { return ans[v] == '0'; })) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;

    return 0;
}