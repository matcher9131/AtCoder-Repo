#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

tuple<ll, ll, ll> getNewState(ll i, ll j, ll from, char type) {
    if (type == 'A') {
        switch (from) {
            case 0: return { i, j+1, 0 };
            case 1: return { i+1, j, 1 };
            case 2: return { i, j-1, 2 };
            case 3: return { i-1, j, 3 };
            default: return { -1, -1, -1 };
        }
    } else if (type == 'B') {
        switch (from) {
            case 0: return { i+1, j, 1 };
            case 1: return { i, j+1, 0 };
            case 2: return { i-1, j, 3 };
            case 3: return { i, j-1, 2 };
            default: return { -1, -1, -1 };
        }
    } else {
        switch (from) {
            case 0: return { i-1, j, 3 };
            case 1: return { i, j-1, 2 };
            case 2: return { i+1, j, 1 };
            case 3: return { i, j+1, 0 };
            default: return { -1, -1, -1 };
        }
    }
}

void solve() {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    // 0: 左から, 1: 上から, 2: 右から, 3: 下から
    vector<pair<ll, ll>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<vector<ll>>> dist(h, vector<vector<ll>>(w, vector<ll>(4, INF)));
    dist[0][0][0] = 0;
    // 距離, i, j, 向き
    priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>, greater<tuple<ll, ll, ll, ll>>> que;
    que.emplace(0, 0, 0, 0);
    while (!que.empty()) {
        auto [d, i, j, from] = que.top();
        // printf("(%lld, %lld, %lld), d = %lld\n", i, j, from, d);
        que.pop();
        if (d > dist[i][j][from]) continue;
        for (char newType = 'A'; newType <= 'C'; ++newType) {
            ll cost = newType != s[i][j];
            auto [ni, nj, nf] = getNewState(i, j, from, newType);
            // printf("ni = %lld, nj = %lld, nf = %lld\n", ni, nj, nf);
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (dist[i][j][from] + cost < dist[ni][nj][nf]) {
                dist[ni][nj][nf] = dist[i][j][from] + cost;
                que.emplace(dist[ni][nj][nf], ni, nj, nf);
            }
        }
    }
    
    ll ans = min(dist[h-1][w-1][0] + (s[h-1][w-1] != 'A'), dist[h-1][w-1][1] + (s[h-1][w-1] != 'B'));
    cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}