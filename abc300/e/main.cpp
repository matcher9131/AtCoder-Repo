#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    ll e2 = 0, e3 = 0, e5 = 0;
    while (n % 2 == 0) {
        n /= 2;
        ++e2;
    }
    while (n % 3 == 0) {
        n /= 3;
        ++e3;
    }
    while (n % 5 == 0) {
        n /= 5;
        ++e5;
    }
    if (n != 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<vector<mint>>> dp(e2+1, vector<vector<mint>>(e3+1, vector<mint>(e5+1)));
    dp[0][0][0] = 1;
    for (ll i = 0; i <= e2; ++i) {
        for (ll j = 0; j <= e3; ++j) {
            for (ll k = 0; k <= e5; ++k) {
                if (i+1 <= e2) dp[i+1][j][k] += dp[i][j][k] / 5;
                if (j+1 <= e3) dp[i][j+1][k] += dp[i][j][k] / 5;
                if (i+2 <= e2) dp[i+2][j][k] += dp[i][j][k] / 5;
                if (k+1 <= e5) dp[i][j][k+1] += dp[i][j][k] / 5;
                if (i+1 <= e2 && j+1 <= e3) dp[i+1][j+1][k] += dp[i][j][k] / 5;
            }
        }
    }

    cout << dp[e2][e3][e5].val() << endl;

    return 0;
}