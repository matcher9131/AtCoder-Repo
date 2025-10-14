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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> s(n);
    s[0] = a[0];
    for (ll i = 1; i < n; ++i) {
        s[i] = s[i-1] + a[i];
    }

    ll ans = INF;
    for (ll i = 0; i < n-1; ++i) {
        chmin(ans, abs(s[n-1] - 2*s[i]));
    }
    cout << ans << endl;

    return 0;
}