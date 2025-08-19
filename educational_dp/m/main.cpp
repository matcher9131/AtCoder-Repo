#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<atcoder::fenwick_tree<mint>> dp(n, atcoder::fenwick_tree<mint>(k+1));
    for (ll j = 0; j <= a[0]; ++j) {
        dp[0].add(j, 1);
    }
    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j <= k; ++j) {
            dp[i].add(j, dp[i-1].sum(max(0LL, j-a[i]), j+1));
        }
    }

    cout << dp[n-1].sum(k, k+1).val() << endl;

    return 0;
}