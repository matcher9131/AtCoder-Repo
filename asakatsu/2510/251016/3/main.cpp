#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

inline bool isSet(ll x, ll i) {
    return x & (1LL << i);
}

int main() {
    ll n, l, r;
    cin >> n >> l >> r;

    ll ans = 0;
    for (ll i = 59; i >= 0; --i) {
        if (!isSet(n, i)) continue;
        ll left = max(l, 1LL << i);
        ll right = min(r, (1LL << (i+1)) - 1);
        if (right >= left) ans += right - left + 1;
    }
    cout << ans << endl;

    return 0;
}