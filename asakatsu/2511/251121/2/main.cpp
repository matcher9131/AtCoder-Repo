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
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    ll open = a[0];
    ll close = a[0] + t;
    for (ll i = 1; i < n; ++i) {
        if (a[i] > close) {
            ans += close - open;
            open = a[i];
            close = a[i] + t;
        } else {
            close = a[i] + t;
        }
    }
    ans += close - open;

    cout << ans << endl;

    return 0;
}