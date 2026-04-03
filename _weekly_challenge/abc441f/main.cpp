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
    ll n, m;
    cin >> n >> m;

    vector<ll> p(n), v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i] >> v[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    vector<vector<bool>> dpt(n+1, vector<bool>(m+1));
    vector<vector<bool>> dpf(n+1, vector<bool>(m+1));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j <= m; ++j) {
            dp[i+1][j] = dp[i][j];
            dpf[i+1][j] = true;
            if (j >= p[i]) {
                if (dp[i][j-p[i]] + v[i] > dp[i+1][j]) {
                    dp[i+1][j] = dp[i][j-p[i]] + v[i];
                    dpt[i+1][j] = true;
                    dpf[i+1][j] = false;
                } else if (dp[i][j-p[i]] + v[i] == dp[i+1][j]) {
                    dpt[i+1][j] = true;
                }
            }
        }
    }

    ll mv = *max_element(dp[n].begin(), dp[n].end());
    unordered_set<ll> jj, njj;
    for (ll j = 0; j <= m; ++j) {
        if (dp[n][j] == mv) jj.insert(j);
    }

    string ans(n, '_');
    for (ll i = n-1; i >= 0; --i) {
        bool buy = false, notBuy = false;
        njj.clear();
        for (const ll j : jj) {
            if (dpt[i+1][j]) {
                buy = true;
                njj.insert(j-p[i]);
            }
            if (dpf[i+1][j]) {
                notBuy = true;
                njj.insert(j);
            }
        }
        ans[i] = buy ? notBuy ? 'B' : 'A' : 'C';
        swap(jj, njj);
    }

    cout << ans << endl;

    return 0;
}