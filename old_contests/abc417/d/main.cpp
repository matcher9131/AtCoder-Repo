#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> p(n), a(n), b(n), sb(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i] >> a[i] >> b[i];
    }
    sb[0] = b[0];
    for (ll i = 1; i < n; ++i) {
        sb[i] = sb[i-1] + b[i];
    }

    ll m = 1000;
    // dp[i][j]: プレゼントをi個もらったときのテンションがjのとき、最終的なテンション
    vector<vector<ll>> dp(n, vector<ll>(m+1));
    for (ll j = 0; j <= m; ++j) {
        if (j <= p[n-1]) dp[n-1][j] = j + a[n-1];
        else dp[n-1][j] = max(0LL, j - b[n-1]);
    }
    for (ll i = n - 2; i >= 0; --i) {
        for (ll j = 0; j <= m; ++j) {
            if (j <= p[i]) dp[i][j] = dp[i+1][j+a[i]];
            else dp[i][j] = dp[i+1][max(0LL, j-b[i])];
        }
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll x;
        cin >> x;
        if (x > m) {
            ll i = lower_bound(sb.begin(), sb.end(), x - m) - sb.begin();
            if (i < n-1) {
                ll j = x - sb[i];
                cout << dp[i+1][j] << endl;
            } else {
                cout << x - sb[n-1] << endl;
            }
        } else {
            cout << dp[0][x] << endl;
        }
    }

    return 0;
}