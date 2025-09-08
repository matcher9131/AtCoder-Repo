#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    // 2i: 赤, 2i-1: 青
    vector<ll> next(2*n, -1);
    for (ll i = 0; i < m; ++i) {
        ll a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        --a;
        --c;
        ll u = 2*a + (b == 'B');
        ll v = 2*c + (d == 'B');
        next[u] = v;
        next[v] = u;
    }

    vector<bool> visited(2*n);
    function<bool(ll)> dfs = [&](ll from) -> bool {
        visited[from] = true;
        ll other = from % 2 ? from-1 : from+1;
        visited[other] = true;
        ll to = next[other];
        if (to == -1) return false;
        if (visited[to]) return true;
        return dfs(to);
    };
    
    ll numCycle = 0, numNonCycle = 0;
    for (ll i = 0; i < 2*n; ++i) {
        if (!visited[i] && next[i] == -1) {
            bool res = dfs(i);
            assert(!res);
            ++numNonCycle;
        }
    }
    for (ll i = 0; i < 2*n; ++i) {
        if (!visited[i]) {
            bool res = dfs(i);
            assert(res);
            ++numCycle;
        }
    }

    cout << numCycle << " " << numNonCycle << endl;

    return 0;
}