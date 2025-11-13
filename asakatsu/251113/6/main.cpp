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
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> cond(n+1);
    for (ll i = 0; i < m; ++i) {
        ll xi, yi, zi;
        cin >> xi >> yi >> zi;
        cond[xi].emplace_back(yi, zi);
    }

    auto isOK = [&](ull bit) {
        for (const auto &[y, z] : cond[popcount(bit)]) {
            ull mask = (1ULL << y) - 1;
            if (popcount(bit & mask) > z) return false;
        }
        return true;
    };

    vector<ll> dp(1LL << n);
    dp[0] = 1;
    for (ull bit = 0; bit < 1ULL<<n; ++bit) {
        for (ll i = 0; i < n; ++i) {
            if (bit & (1ULL << i)) continue;
            ll newBit = bit | (1ULL << i);
            if (isOK(newBit)) dp[newBit] += dp[bit];
        }
    }
    cout << dp[(1LL << n) - 1] << endl;

    return 0;
}