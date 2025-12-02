#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

inline ll ceil10k(ll x) {
    return x>=0 ? (x+9999) / 10000 * 10000 : x / 10000 * 10000;
}
inline ll floor10k(ll x) {
    return x>=0 ? x / 10000 * 10000 : (x-9999) / 10000 * 10000;
}

int main() {
    double x0d, y0d, rd;
    cin >> x0d >> y0d >> rd;

    ll x0 = round(10000 * x0d);
    ll y0 = round(10000 * y0d);
    ll r = round(10000 * rd);

    ll left = ceil10k(x0-r);
    ll right = floor10k(x0+r);
    ll ans = 0;
    for (ll x = left; x <= right; x += 10000) {
        ll dx = x - x0;
        long double dy = sqrtl(r*r - dx*dx);
        ll bottom = ceil10k((ll)ceil(y0-dy));
        ll top = floor10k((ll)floor(y0+dy));
        ans += (top - bottom) / 10000 + 1;
    }
    cout << ans << endl;

    return 0;
}