#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> d(n+1, vector<ll>(n+1, INF));
    for (ll i = 0; i < n+1; ++i) {
        d[i][i] = 0;
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        d[a][b] = min(d[a][b], w);
        d[b][a] = min(d[b][a], w);
    }
    ll k, t0;
    cin >> k >> t0;
    for (ll i = 0; i < k; ++i) {
        ll di;
        cin >> di;
        --di;
        d[di][n] = t0;
        d[n][di] = 0;
    }

    for (int k = 0; k < n+1; ++k) {
        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < n+1; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x, y, w;
            cin >> x >> y >> w;
            --x;
            --y;
            if (w >= d[x][y]) continue;
            d[x][y] = w;
            d[y][x] = w;
            for (ll i = 0; i < n+1; ++i) {
                for (ll j = 0; j < n+1; ++j) {
                    d[i][j] = min({d[i][j], d[i][x] + d[x][y] + d[y][j], d[i][y] + d[y][x] + d[x][j]});
                }
            }
        } else if (type == 2) {
            ll x;
            cin >> x;
            --x;
            if (d[x][n] == t0) continue;
            d[x][n] = t0;
            d[n][x] = 0;
            for (ll i = 0; i < n+1; ++i) {
                for (ll j = 0; j < n+1; ++j) {
                    d[i][j] = min({d[i][j], d[i][x] + d[x][n] + d[n][j], d[i][n] + d[n][x] + d[x][j]});
                }
            }
        } else {
            ll ans = 0;
            for (ll i = 0; i < n; ++i) {
                for (ll j = 0; j < n; ++j) {
                    if (d[i][j] < INF) ans += d[i][j];
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}