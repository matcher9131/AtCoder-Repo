#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, _p;
    cin >> n >> _p;
    mint p = (mint)_p / 100;

    // dp[i]: 残りHPがiのときの倒すまでの攻撃回数の期待値
    vector<mint> dp(n+1);
    dp[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        dp[i] = 1 + p * dp[i-2] + (1-p) * dp[i-1];
    }

    cout << dp[n].val() << endl;
    return 0;
}