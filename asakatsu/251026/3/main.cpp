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
    ll l, r;
    cin >> l >> r;

    if (r-l+1 >= 2019) {
        cout << 0 << endl;
    } else {
        ll ans = INF;
        for (ll i = l; i < r; ++i) {
            for (ll j = l+1; j <= r; ++j) {
                chmin(ans, i*j%2019);
            }
        }
        cout << ans << endl;
    }

    return 0;
}