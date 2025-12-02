#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

using S = mint;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}
using SegTree = atcoder::segtree<S, op, e>;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<SegTree> dp(n+1, SegTree(3001));
    dp[0].set(0, 1);
    for (ll i = 0; i < n; ++i) {
        for (ll j = a[i]; j <= b[i]; ++j) {
            dp[i+1].set(j, dp[i].prod(0, j+1));
        }
    }
    
    mint ans = 0;
    for (ll j = a[n-1]; j <= b[n-1]; ++j) {
        ans += dp[n].get(j);
    }
    cout << ans.val() << endl;

    return 0;
}