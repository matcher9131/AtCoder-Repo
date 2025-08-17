#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));

    function<ll(ll, ll)> dfs = [&](ll i, ll j) -> ll {
        if (dp[i][j] != INF) return dp[i][j];
        if (i == n && j == m) return 0;

        ll res = -INF;
        if (i < n) {
            res = max(res, -dfs(i+1, j) + a[i]);
        }
        if (j < m) {
            res = max(res, -dfs(i, j+1) + b[j]);
        }

        return dp[i][j] = res;
    };

    cout << (dfs(0, 0) + accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL)) / 2 << endl;

    return 0;
}