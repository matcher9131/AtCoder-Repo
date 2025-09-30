#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, k, l;
    cin >> n >> k >> l;

    mint ans = 1;
    for (ll i = 0; i < n; ++i) {
        if (i < n-k) ans *= l-i;
        else ans *= l-(n-k);
    }

    cout << ans.val() << endl;
    return 0;
}