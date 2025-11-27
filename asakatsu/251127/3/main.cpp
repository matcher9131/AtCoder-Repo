#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    string s;
    cin >> s;
    ll n = s.size();

    string t = "chokudai";
    vector<vector<mint>> dp(n+1, vector<mint>(9));
    dp[0][0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= 8; ++j) {
            dp[i+1][j] += dp[i][j];
            if (j < 8 && s[i] == t[j]) dp[i+1][j+1] += dp[i][j];
        }
    }
    cout << dp[n][8].val() << endl;

    return 0;
}