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

    vector<vector<mint>> dp(n, vector<mint>(2));
    dp[0][0] = 1;
    dp[0][1] = 2;
    for (ll i = 1; i < n; ++i) {
        if (s[i] == '1') {
            dp[i][0] = 3 * dp[i-1][0] + dp[i-1][1];
            dp[i][1] = 2 * dp[i-1][1];
        } else {
            dp[i][0] = 3 * dp[i-1][0];
            dp[i][1] = dp[i-1][1];
        }
    }
    cout << (dp[n-1][0] + dp[n-1][1]).val() << endl;

    return 0;
}