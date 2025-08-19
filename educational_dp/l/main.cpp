#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, -INF));
    function<ll(ll,ll)> dfs = [&](ll i, ll j) -> ll {
        if (i > j) return 0;
        if (dp[i][j] != -INF) return dp[i][j];
        ll res = -INF;
        res = max(res, -dfs(i+1, j) + a[i]);
        if (i != j) res = max(res, -dfs(i, j-1) + a[j]);
        return dp[i][j] = res;
    };

    cout << dfs(0, n-1) << endl;

    return 0;
}