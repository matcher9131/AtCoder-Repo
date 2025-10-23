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
    ll n, p;
    cin >> n >> p;

    mint prob = mint(p) / 100;
    vector<mint> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        dp[i] = 1 + (1 - prob) * dp[i-1] + prob * dp[i-2];
    }
    cout << dp[n].val() << endl;

    return 0;
}