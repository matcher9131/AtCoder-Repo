#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    string s;
    cin >> s;
    vector<ll> n;
    for (ll i = 0; i < (ll)s.size(); ++i) {
        n.push_back(s[i] - '0');
    }
    ll m = n.size();

    auto search = [&](ll p) -> ll {
        // dp[i][j][k][l]: i桁で桁和がjでmod pがkに一致するものの個数
        // l=0: Nの上からi桁より小さい, l=1: Nの上からi桁と一致
        vector<vector<vector<vector<ll>>>> dp(m+1, vector<vector<vector<ll>>>(p+1, vector<vector<ll>>(p, vector<ll>(2))));
        dp[0][0][0][1] = 1;
        for (ll i = 0; i < m; ++i) {
            for (ll j = 0; j <= p; ++j) {
                for (ll k = 0; k < p; ++k) {
                    for (ll x = 0; x < 10; ++x) {
                        if (j + x <= p) dp[i+1][j+x][(10*k + x) % p][0] += dp[i][j][k][0];
                    }
                    for (ll x = 0; x < n[i]; ++x) {
                        if (j + x <= p) dp[i+1][j+x][(10*k + x) % p][0] += dp[i][j][k][1];
                    }
                    if (j + n[i] <= p) dp[i+1][j+n[i]][(10*k + n[i]) % p][1] += dp[i][j][k][1];
                }
            }
        }

        return dp[m][p][0][0] + dp[m][p][0][1];
    };
    

    ll ans = 0;
    for (ll p = 1; p <= 126; ++p) {
        ans += search(p);
    }

    cout << ans << endl;

    return 0;
}