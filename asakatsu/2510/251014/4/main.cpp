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
    vector<vector<ll>> a(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> b(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> b[i][j];
        }
    }

    auto colSwap = [&](vector<vector<ll>> &x, ll j) -> void {
        for (ll i = 0; i < h; ++i) {
            swap(x[i][j], x[i][j+1]);
        }
    };

    map<vector<vector<ll>>, ll> dist;
    dist[a] = 0;
    queue<vector<vector<ll>>> que;
    que.push(a);
    while (!que.empty()) {
        vector<vector<ll>> x = que.front();
        if (x == b) {
            cout << dist[x] << endl;
            return 0;
        }
        que.pop();
        ll d = dist[x];
        for (ll i = 0; i < h-1; ++i) {
            swap(x[i], x[i+1]);
            if (!dist.contains(x)) {
                dist[x] = d+1;
                que.push(x);
            }
            swap(x[i], x[i+1]);
        }
        for (ll j = 0; j < w-1; ++j) {
            colSwap(x, j);
            if (!dist.contains(x)) {
                dist[x] = d+1;
                que.push(x);
            }
            colSwap(x, j);
        }
    }

    cout << -1 << endl;

    return 0;
}