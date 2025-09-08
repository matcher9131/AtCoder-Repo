#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n+1, vector<ll>(n+1, INF));
    auto chMin = [&](int i, int j, ll val) {
        g[i][j] = min(g[i][j], val);
        g[j][i] = min(g[j][i], val);
    };
    for (ll i = 0; i <= n; ++i) {
        g[i][i] = 0;
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        chMin(a, b, 2*w);
    }

    ll kk, t;
    cin >> kk >> t;
    for (ll i = 0; i < kk; ++i) {
        int di;
        cin >> di;
        --di;
        chMin(di, n, t);
    }

    for (int k = 0; k <= n; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                chMin(i, j, g[i][k] + g[k][j]);
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
            chMin(x, y, 2*w);
            for (ll i = 0; i <= n; ++i) {
                for (ll j = 0; j <= n; ++j) {
                    chMin(i, j, min(g[i][x] + g[x][y] + g[y][j], g[i][y] + g[y][x] + g[x][j]));
                }
            }
        } else if (type == 2){
            ll x;
            cin >> x;
            --x;
            chMin(x, n, t);
            for (ll i = 0; i <= n; ++i) {
                for (ll j = 0; j <= n; ++j) {
                    chMin(i, j, min(g[i][x] + g[x][n] + g[n][j], g[i][n] + g[n][x] + g[x][j]));
                }
            }
        } else {
            ll ans = 0;
            for (ll i = 0; i < n; ++i) {
                for (ll j = 0; j < n; ++j) {
                    if (g[i][j] >= INF) continue;
                    ans += g[i][j];
                }
            }
            cout << ans/2 << endl;
        }
    }

    return 0;
}