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
    ll s;
    cin >> s;
    if (s < 3) {
        cout << 0 << endl;
        return 0;
    }

    vector<mint> dp(s+1, 1);
    for (ll x = 3; x <= s; ++x) {
        for (ll y = 3; y <= s-x; ++y) {
            dp[x+y] += dp[x];
        }
    }
    cout << dp[s].val() << endl;

    return 0;
}