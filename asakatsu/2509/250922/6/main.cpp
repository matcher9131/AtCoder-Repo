#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll nq, k;
    cin >> nq >> k;
    vector<mint> dp(k+1);
    dp[0] = 1;

    while (nq--) {
        char type;
        ll x;
        cin >> type >> x;
        if (type == '+') {
            for (ll i = k; i >= x; --i) {
                dp[i] += dp[i-x];
            }
        } else {
            for (ll i = x; i <= k; ++i) {
                dp[i] -= dp[i-x];
            }
        }
        cout << dp[k].val() << endl;
    }

    return 0;
}