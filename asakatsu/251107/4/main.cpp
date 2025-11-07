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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    vector<vector<ll>> c(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        string si;
        cin >> si;
        for (ll j = 0; j < n; ++j) {
            if (si[j] == 'Y') {
                d[i][j] = 1;
                c[i][j] = a[j];
            }
        }
    }
    

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    c[i][j] = c[i][k] + c[k][j];
                } else if (d[i][k] + d[k][j] == d[i][j]) {
                    chmax(c[i][j], c[i][k] + c[k][j]);
                }
            }
        }
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        if (d[u][v] == INF) {
            cout << "Impossible" << "\n";
        } else {
            cout << d[u][v] << " " << c[u][v] + a[u] << "\n";
        }
    }

    return 0;
}