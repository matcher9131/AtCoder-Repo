#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

inline ll pmod(ll x, ll y) {
    ll r = x % y;
    return r >= 0 ? r : r+y;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> x(m), y(m);
    for (ll i = 0; i < m; ++i) {
        cin >> x[i] >> y[i];
        --x[i];
        --y[i];
    }

    vector<mint> dp(n);
    dp[0] = 1;

    for (ll ki = 0; ki < k; ++ki) {
        vector<pair<ll, mint>> addList;
        for (ll mi = 0; mi < m; ++mi) {
            ll u = pmod(x[mi] - ki, n);
            ll v = pmod(y[mi] - (ki+1), n);
            addList.emplace_back(v, dp[u]);
        }
        for (const auto &[v, val] : addList) {
            dp[v] += val;
        }
    }

    cout << accumulate(dp.begin(), dp.end(), (mint)0).val() << endl;

    return 0;
}