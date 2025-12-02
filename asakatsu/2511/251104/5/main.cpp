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
    string s;
    cin >> s;
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'R') c[i] = 1;
        else if (s[i] == 'G') c[i] = 2;
        else c[i] = 3;
    }

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(4, vector<ll>(4, INF)));
    vector<vector<vector<pair<ll, ll>>>> prev(n, vector<vector<pair<ll, ll>>>(4, vector<pair<ll, ll>>(4)));
    dp[0][c[0]][c[0]] = 1;
    prev[0][c[0]][c[0]] = { 0, 0 };
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j < 4; ++j) {
            for (ll k = 0; k < 4; ++k) {
                if (dp[i-1][j][k] == INF) continue;
                if (c[i] == j) {
                    if (dp[i][prev[i-1][j][k].first][k] > dp[i-1][j][k] - 1) {
                        dp[i][prev[i-1][j][k].first][k] = dp[i-1][j][k] - 1;
                        prev[i][prev[i-1][j][k].first][k] = { prev[i-2]}
                    }
                } else {
                    if (dp[i][c[i]][k] > dp[i-1][j][k] + 1) {
                        dp[i][c[i]][k] = dp[i-1][j][k] + 1;
                        prev[i][c[i]][k] = { j, prev[i-1][j][k].second };
                    }
                }
            }
        }
    }

    return 0;
}