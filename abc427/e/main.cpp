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
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    map<vector<string>, ll> dist;
    dist[s] = 0;
    queue<vector<string>> que;
    que.push(s);
    while (!que.empty()) {
        vector<string> state = que.front();
        que.pop();
        for (const ll nv : g[v]) {
            if (dist[nv] < INF) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    return 0;
}