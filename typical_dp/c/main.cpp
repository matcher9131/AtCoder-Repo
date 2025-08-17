#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

double wp(ll rp, ll rq) {
    return 1.0 / (1.0 + pow(10.0, (rq - rp) / 400.0));
}

int main() {
    ll k;
    cin >> k;
    ll n = 1LL << k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<double>> dp(n, vector<double>(k));
    for (ll i = 0; i < n; i += 2) {
        dp[i][0] = wp(a[i], a[i+1]);
        dp[i+1][0] = wp(a[i+1], a[i]);
    }
    for (ll ki = 1; ki < k; ++ki) {
        for (ll i = 0; i < n; ++i) {
            ll left = ((i >> ki) ^ 1) << ki;
            ll right = left + (1 << ki);
            for (ll j = left; j < right; ++j) {
                dp[i][ki] += dp[j][ki-1] * wp(a[i], a[j]);
            }
            dp[i][ki] *= dp[i][ki-1];
        }
    }

    cout << fixed << setprecision(15);
    for (ll i = 0; i < n; ++i) {
        cout << dp[i][k-1] << endl;
    }

    return 0;
}