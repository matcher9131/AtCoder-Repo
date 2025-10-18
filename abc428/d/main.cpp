#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll c, d;
    cin >> c >> d;

    ll ans = 0;
    for (ll i = 1; i <= 10; ++i) {
        if (pow(10, i) < c) continue;
        ll latterMin = max(c+1, (ll)pow(10, i-1));
        ll latterMax = min((ll)pow(10, i) - 1, c+d);
        if (latterMin <= latterMax) {
            ll left = c * (ll)pow(10, i) + latterMin;
            ll right = c * (ll)pow(10, i) + latterMax;
            ll ansL = (ll)ceil(sqrtl(left));
            ll ansR = (ll)floor(sqrtl(right));
            if (ansR >= ansL) ans += ansR - ansL + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}