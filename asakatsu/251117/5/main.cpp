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
    ll n, nc;
    cin >> n >> nc;
    vector<vector<ll>> d(nc, vector<ll>(nc));
    for (ll i = 0; i < nc; ++i) {
        for (ll j = 0; j < nc; ++j) {
            cin >> d[i][j];
        }
    }
    vector<vector<ll>> colDic(3, vector<ll>(nc));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            ll c;
            cin >> c;
            --c;
            ++colDic[(i+j+2)%3][c];
        }
    }

    ll ans = INF;
    for (ll x = 0; x < nc; ++x) {
        for (ll y = 0; y < nc; ++y) {
            if (x == y) continue;
            for (ll z = 0; z < nc; ++z) {
                if (x == z || y == z) continue;
                ll cur = 0;
                for (ll j = 0; j < nc; ++j) {
                    cur += colDic[0][j] * d[j][x];
                }
                for (ll j = 0; j < nc; ++j) {
                    cur += colDic[1][j] * d[j][y];
                }
                for (ll j = 0; j < nc; ++j) {
                    cur += colDic[2][j] * d[j][z];
                }
                chmin(ans, cur);
            }
        }
    }

    cout << ans << endl;

    return 0;
}