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

    vector<bool> isWhite(n);
    vector<vector<ll>> blackGroups;
    for (ll ki = 0; ki < k; ++ki) {
        vector<ll> group;
        vector<ll> dist(n, INF);
        dist[p[ki]] = 0;
        queue<ll> que;
        que.push(p[ki]);
        while (!que.empty()) {
            ll v = que.front();
            que.pop();
            if (dist[v] == d[ki]) {
                group.push_back(v);
                continue;
            } else if (dist[v] < d[ki]) {
                isWhite[v] = true;
            }
            for (const ll nv : g[v]) {
                if (dist[nv] < INF) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        blackGroups.push_back(group);
    }

    for (const auto& group : blackGroups) {
        if (all_of(group.begin(), group.end(), [&](ll v) { return isWhite[v]; })) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (ll i = 0; i < n; ++i) {
        cout << (isWhite[i] ? '0' : '1');
    }
    cout << endl;

    return 0;
}