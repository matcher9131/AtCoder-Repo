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
    
    vector<ll> ans(n);
    ll aMax = a[0];
    ans[0] = a[0] * b[0];
    for (ll i = 1; i < n; ++i) {
        chmax(aMax, a[i]);
        chmax(ans[i], max(ans[i-1], aMax * b[i]));
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}