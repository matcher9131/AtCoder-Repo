#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, d;
    cin >> n >> d;

    ll a = 0, b = 0, c = 0;
    while (d % 2 == 0) {
        d /= 2;
        ++a;
    }
    while (d % 3 == 0) {
        d /= 3;
        ++b;
    }
    while (d % 5 == 0) {
        d /= 5;
        ++c;
    }
    if (d != 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<vector<vector<double>>>> dp(n+1, vector<vector<vector<double>>>(a+1, vector<vector<double>>(b+1, vector<double>(c+1))));
    dp[0][0][0][0] = 1.0;
    for (ll i = 0; i < n; ++i) {
        for (ll x = 0; x <= a; ++x) {
            for (ll y = 0; y <= b; ++y) {
                for (ll z = 0; z <= c; ++z) {
                    dp[i+1][x][y][z] += dp[i][x][y][z] / 6.0;
                    dp[i+1][min(x+1, a)][y][z] += dp[i][x][y][z] / 6.0;
                    dp[i+1][x][min(y+1, b)][z] += dp[i][x][y][z] / 6.0;
                    dp[i+1][min(x+2, a)][y][z] += dp[i][x][y][z] / 6.0;
                    dp[i+1][x][y][min(z+1, c)] += dp[i][x][y][z] / 6.0;
                    dp[i+1][min(x+1, a)][min(y+1, b)][z] += dp[i][x][y][z] / 6.0;
                }
            }
        }
    }

    cout << setprecision(15) << dp[n][a][b][c] << endl;

    return 0;
}