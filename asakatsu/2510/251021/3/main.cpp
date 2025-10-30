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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (ll i = 1; i < n; ++i) {
        chmax(dp[i][0], max(dp[i-1][0], dp[i-1][1] + 2*a[i]));
        chmax(dp[i][1], max(dp[i-1][1], dp[i-1][0] + a[i]));
    }
    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;

    return 0;
}