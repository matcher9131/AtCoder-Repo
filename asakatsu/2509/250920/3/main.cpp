#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<vector<vector<ll>>> a(n, vector<vector<ll>>(n, vector<ll>(n)));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll k = 0; k < n; ++k) {
                cin >> a[i][j][k];
            }
        }
    }

    vector<vector<vector<ll>>> s(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1)));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll k = 0; k < n; ++k) {
                s[i+1][j+1][k+1] = s[i][j+1][k+1] + s[i+1][j][k+1] + s[i+1][j+1][k] - s[i+1][j][k] - s[i][j+1][k] - s[i][j][k+1] + s[i][j][k] + a[i][j][k];
            }
        }
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll xl, xr, yl, yr, zl, zr;
        cin >> xl >> xr >> yl >> yr >> zl >> zr;
        --xl;
        --yl;
        --zl;
        ll ans = s[xr][yr][zr] - s[xl][yr][zr] - s[xr][yl][zr] - s[xr][yr][zl] + s[xr][yl][zl] + s[xl][yr][zl] + s[xl][yl][zr] - s[xl][yl][zl];
        cout << ans << endl;
    }

    return 0;
}