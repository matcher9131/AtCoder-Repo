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

    ll x = 0, y = 0, z = 0;
    while (n%2 == 0) {
        n /= 2;
        ++x;
    }
    while (n%3 == 0) {
        n /= 3;
        ++y;
    }
    while (n%5 == 0) {
        n /= 5;
        ++z;
    }
    if (n != 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<vector<mint>>> dp(x+5, vector<vector<mint>>(y+5, vector<mint>(z+5)));
    dp[0][0][0] = 1;
    for (ll i = 0; i <= x; ++i) {
        for (ll j = 0; j <= y; ++j) {
            for (ll k = 0; k <= z; ++k) {
                mint p = dp[i][j][k] / 5;
                dp[i+1][j][k] += p;
                dp[i][j+1][k] += p;
                dp[i+2][j][k] += p;
                dp[i][j][k+1] += p;
                dp[i+1][j+1][k] += p;
            }
        }
    }

    cout << dp[x][y][z].val() << endl;

    return 0;
}