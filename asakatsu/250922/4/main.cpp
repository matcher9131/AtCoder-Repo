#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<ll>> dp(n, vector<ll>(3, INF));
    dp[0][0] = s[0] == '1';
    dp[0][1] = s[0] == '0';

    for (ll i = 0; i < n-1; ++i) {
        if (dp[i][0] < INF) {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + (s[i+1] == '1'));
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + (s[i+1] == '0'));
        }
        if (dp[i][1] < INF) {
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + (s[i+1] == '0'));
            dp[i+1][2] = min(dp[i+1][2], dp[i][1] + (s[i+1] == '1'));
        }
        if (dp[i][2] < INF) {
            dp[i+1][2] = min(dp[i+1][2], dp[i][2] + (s[i+1] == '1'));
        }
    }

    cout << *min_element(dp[n-1].begin(), dp[n-1].end()) << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}