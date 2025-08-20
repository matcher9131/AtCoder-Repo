#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> s(n+1);
    for (ll i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n+1));
    function<ll(ll,ll)> dfs = [&](ll left, ll right) -> ll {
        if (dp[left][right]) return dp[left][right];
        if (left + 1 == right) return 0;
        ll res = INF;
        for (ll mid = left+1; mid < right; ++mid) {
            res = min(res, s[right] - s[left] + dfs(left, mid) + dfs(mid, right));
        }
        return dp[left][right] = res;
    };

    cout << dfs(0, n) << endl;

    return 0;
}