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
    vector<ull> fact(n), mask(n);
    for (ll i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; ++j) {
            ll x, y;
            cin >> x >> y;
            --x;
            mask[i] |= 1ULL << x;
            if (y == 1) fact[i] |= 1ULL << x;
        }
    }

    auto meets = [&](ull bit) -> bool {
        for (ll i = 0; i < n; ++i) {
            if (bit & (1ULL << i)) {
                if ((bit & mask[i]) != fact[i]) return false;
            }
        }
        return true;
    };

    ll ans = 0;
    for (ull bit = 0; bit < 1ULL << n; ++bit) {
        if (meets(bit)) chmax(ans, (ll)popcount(bit));
    }
    cout << ans << endl;

    return 0;
}