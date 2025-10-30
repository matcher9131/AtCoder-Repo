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
    ll n;
    cin >> n;
    vector<ll> a(n), s(n+1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        s[i+1] = s[i] + a[i];
    }

    vector<vector<mint>> dp(n, vector<mint>(n));
    for (ll i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }



    return 0;
}