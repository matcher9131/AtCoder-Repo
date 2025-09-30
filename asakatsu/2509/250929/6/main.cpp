#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n-1);
    for (ll i = 0; i < n-1; ++i) {
        cin >> a[i];
    }

    atcoder::fenwick_tree<mint> dp(n);
    for (ll i = n-2; i >= 0; --i) {
        dp.add(i, dp.sum(i+1, min(n, i+a[i]+1)) / a[i] + mint(a[i]).inv() + 1);
    }
    cout << dp.sum(0,1).val() << endl;

    return 0;
}