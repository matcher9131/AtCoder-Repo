#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n, k;
    cin >> n >> k;
    ll m = bit_width((ull)n);

    vector<vector<vector<mint>>> dpc(m, vector<vector<mint>>(k+1, vector<mint>(2)));
    vector<vector<vector<mint>>> dps(m, vector<vector<mint>>(k+1, vector<mint>(2)));
    dpc[0][0][0] = 1;
    dpc[0][1][1] = 1;
    dps[0][0][0] = 0;
    dps[0][1][1] = mint(2).pow(m-1);
    for (ll i = 1; i < m; ++i) {
        for (ll j = 0; j <= k; ++j) {
            if (n & (1LL << (m-1-i))) {
                dpc[i][j][0] += dpc[i-1][j][0] + dpc[i-1][j][1];
                dps[i][j][0] += dps[i-1][j][0] + dps[i-1][j][1];
                if (j < k) {
                    dpc[i][j+1][0] += dpc[i-1][j][0];
                    dpc[i][j+1][1] += dpc[i-1][j][1];
                    dps[i][j+1][0] += dps[i-1][j][0] + mint(2).pow(m-1-i) * dpc[i-1][j][0];
                    dps[i][j+1][1] += dps[i-1][j][1] + mint(2).pow(m-1-i) * dpc[i-1][j][1];
                }
            } else {
                dpc[i][j][0] += dpc[i-1][j][0];
                dpc[i][j][1] += dpc[i-1][j][1];
                dps[i][j][0] += dps[i-1][j][0];
                dps[i][j][1] += dps[i-1][j][1];
                if (j < k) {
                    dpc[i][j+1][0] += dpc[i-1][j][0];
                    dps[i][j+1][0] += dps[i-1][j][0] + mint(2).pow(m-1-i) * dpc[i-1][j][0];
                }
            }
        }
    }
    cout << (dps[m-1][k][0] + dps[m-1][k][1]).val() << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}