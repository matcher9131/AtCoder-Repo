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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> s(n+1);
    for (ll i = 0; i < n; ++i) {
        s[i+1] = (s[i] + a[i]) % m;
    }

    atcoder::fenwick_tree<ll> fw(m);
    vector<ll> numLessRight(n+1);
    for (ll i = n; i >= 0; --i) {
        numLessRight[i] = fw.sum(0, s[i]);
        fw.add(s[i], 1);
    }

    vector<ll> ss(n+1);
    for (ll i = 1; i < n+1; ++i) {
        ss[i] = ss[i-1] + s[i];
    }

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ans += ss[n] - ss[i-1] - (n - (i-1)) * s[i-1] + m * numLessRight[i-1];
    }
    cout << ans << endl;


    return 0;
}