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
    vector<ll> p(n), a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i] >> a[i] >> b[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(1001));
    for (ll j = 0; j <= p[n-1]; ++j) {
        dp[n-1][j] = j + a[n-1];
    }
    for (ll j = p[n-1]+1; j <= 1000; ++j) {
        dp[n-1][j] = max(0LL, j - b[n-1]);
    }
    for (ll i = n - 2; i >= 0; --i) {
        for (ll j = 0; j <= p[i]; ++j) {
            dp[i][j] = dp[i+1][j + a[i]];
        }
        for (ll j = p[i]+1; j <= 1000; ++j) {
            dp[i][j] = dp[i+1][max(0LL, j - b[i])];
        }
    }

    vector<ll> sumB(n+1);
    for (ll i = 0; i < n; ++i) {
        sumB[i+1] = sumB[i] + b[i];
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll x;
        cin >> x;
        if (x > 1000) {
            ll i = lower_bound(sumB.begin(), sumB.end(), x-1000) - sumB.begin();
            if (i < n) cout << dp[i][x-sumB[i]] << endl;
            else cout << x - sumB[n] << endl;
        } else {
            cout << dp[0][x] << endl;
        }
    }

    return 0;
}