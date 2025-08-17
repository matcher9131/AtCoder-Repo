#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e16;

using S = mint;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}

int main() {
    ll n, k;
    cin >> n >> k;

    atcoder::segtree<S, op, e> dp(k);
    dp.set(1, 1);
    for (ll i = 1; i < n; ++i) {
        dp.set((-i % k + k) % k, dp.all_prod());
    }

    mint ans = dp.all_prod() - dp.get((-(n-1) % k + k) % k);
    cout << ans.val() << endl;

    return 0;
}