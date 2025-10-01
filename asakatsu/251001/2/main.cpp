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
    ll n, nq;
    cin >> n >> nq;

    ll ans = 0;
    ll l = 0, r = 1;
    while (nq--) {
        char h;
        ll t;
        cin >> h >> t;
        --t;
        ll &x = h == 'L' ? l : r;
        ll y = h == 'L' ? r : l;
        if (x == t) continue;
        if (x > t) {
            if (t < y && y < x) {
                ans += t + n - x;
            } else {
                ans += x - t;
            }
        } else {
            if (x < y && y < t) {
                ans += x + n - t;
            } else {
                ans += t - x;
            }
        }
        x = t;
    }
    cout << ans << endl;

    return 0;
}