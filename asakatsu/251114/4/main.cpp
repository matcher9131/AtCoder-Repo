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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (k > *max_element(a.begin(), a.end())) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if (n == 1) {
        cout << (k == a[0] ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        return 0;
    }

    ll g = gcd(a[0], a[1]);
    for (ll i = 2; i < n; ++i) {
        g = gcd(g, a[i]);
    }

    cout << (k%g == 0 ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;
}