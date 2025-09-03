#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    set<pair<ll, ll>> h;
    for (ll i = 0; i < m; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        h.emplace(xi, yi);
    }

    vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(n+1, vector<mint>(n+1)));
    dp[0][0][0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll k = 0; k < n; ++k) {
                ll x = i * a + j * c + k * e;
                ll y = i * b + j * d + k * f;
                {
                    ll nx = x + a;
                    ll ny = y + b;
                    if (!h.contains({nx, ny})) dp[i+1][j][k] += dp[i][j][k];
                }
                {
                    ll nx = x + c;
                    ll ny = y + d;
                    if (!h.contains({nx, ny})) dp[i][j+1][k] += dp[i][j][k];
                }
                {
                    ll nx = x + e;
                    ll ny = y + f;
                    if (!h.contains({nx, ny})) dp[i][j][k+1] += dp[i][j][k];
                }
            }
        }
    }

    mint ans = 0;
    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j <= n-i; ++j) {
            ans += dp[i][j][n-i-j];
        }
    }

    cout << ans.val() << endl;
    return 0;
}