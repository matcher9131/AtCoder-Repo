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
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for (ll i = 0; i < n; ++i) {
        d[i][i] = 0;
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        chmin(d[a][b], c);
        chmin(d[b][a], c);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    ll k;
    cin >> k;
    while (k--) {
        ll x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        chmin(d[x][y], z);
        chmin(d[y][x], z);
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                chmin(d[i][j], min(d[i][x] + d[x][y] + d[y][j], d[i][y] + d[y][x] + d[x][j]));
                chmin(d[j][i], min(d[j][x] + d[x][y] + d[y][i], d[j][y] + d[y][x] + d[x][i]));
            }
        }
        
        ll ans = 0;
        for (ll i = 0; i < n; ++i) {
            for (ll j = i+1; j < n; ++j) {
                ans += d[i][j];
            }
        }
        cout << ans << endl;
    }

    return 0;
}