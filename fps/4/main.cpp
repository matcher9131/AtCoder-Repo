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
    ll n, k;
    cin >> n >> k;
    vector<ll> l(k), r(k);
    for (ll i = 0; i < k; ++i) {
        cin >> l[i] >> r[i];
        ++r[i];
    }

    // f = ∑(x^l[k] - x^r[k])/(1-x)
    // ans = ∑[x^N]f^n = [x^N]1/(1-f)
    // (1 - x - ∑(x^l[k] - x^r[k]))G = 1-x
    // a[i] = a[i-1] + ∑(a[i-l[k]] - a[i-r[k]])
    // 右辺=1を求めてから1-x倍が簡明
    vector<mint> ans(n);
    ans[0] = 1;
    for (ll i = 1; i < n; ++i) {
        ans[i] = ans[i-1];
        for (ll ki = 0; ki < k; ++ki) {
            if (i-l[ki] >= 0) ans[i] += ans[i-l[ki]];
            if (i-r[ki] >= 0) ans[i] -= ans[i-r[ki]];
        }
    }
    for (ll i = n-1; i >= 1; --i) {
        ans[i] -= ans[i-1];
    }
    cout << ans[n-1].val() << endl;

    return 0;
}