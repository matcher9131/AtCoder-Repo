#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/scc>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> p[i];
    }

    vector<vector<ll>> s(n, vector<ll>(n, INF));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i == j) continue;
            ll dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            s[i][j] = (dist + p[i] - 1) / p[i];
        }
    }

    auto isOK = [&](ll x) -> bool {
        atcoder::scc_graph g(n);
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (s[i][j] <= x) g.add_edge(i, j);
            }
        }

        vector<unordered_set<int>> scc;
        vector<ll> giRev(n);
        for (const auto &group : g.scc()) {
            unordered_set<int> s;
            for (const int v : group) {
                s.insert(v);
                giRev[v] = scc.size();
            }
            scc.push_back(s);
        }
        int m = scc.size();

        vector<unordered_set<int>> g2(m);
        for (ll gi = 0; gi < m; ++gi) {
            for (const int from : scc[gi]) {
                for (ll to = 0; to < n; ++to) {
                    if (from == to) continue;
                    if (s[from][to] > x) continue;
                    if (giRev[from] == giRev[to]) continue;
                    g2[gi].insert(giRev[to]);
                }
            }
        }

        vector<bool> visited(m);
        function<void(ll)> dfs = [&](ll from) -> void {
            visited[from] = true;
            for (const ll to : g2[from]) {
                if (visited[to]) continue;
                dfs(to);
            }
        };
        dfs(0);
        return all_of(visited.begin(), visited.end(), [&](bool val) { return val; });
    };

    ll ng = 0;
    ll ok = 4e9 + 1;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}