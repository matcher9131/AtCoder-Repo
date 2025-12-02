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
    ll n;
    cin >> n;
    vector<vector<ll>> a(2, vector<ll>(n));
    for (ll i = 0; i < 2; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<ll> s1(n);
    s1[0] = a[0][0];
    for (ll i = 1; i < n; ++i) {
        s1[i] = s1[i-1] + a[0][i];
    }
    vector<ll> s2(n);
    s2[n-1] = a[1][n-1];
    for (ll i = n-2; i >= 0; --i) {
        s2[i] = s2[i+1] + a[1][i];
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        chmax(ans, s1[i] + s2[i]);
    }
    cout << ans << endl;

    return 0;
}