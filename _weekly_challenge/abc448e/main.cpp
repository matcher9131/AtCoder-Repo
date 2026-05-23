#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

vector<vector<ll>> mat_mul_mod(vector<vector<ll>> &x, vector<vector<ll>> &y, ll m) {
    assert(x[0].size() == y.size());
    vector<vector<ll>> res(x.size(), vector<ll>(y[0].size()));
    for (ll i = 0; i < (ll)x.size(); ++i) {
        for (ll j = 0; j < (ll)y.size(); ++j) {
            for (ll k = 0; k < (ll)y[0].size(); ++k) {
                res[i][j] += x[i][k] * y[k][j];
                res[i][j] %= m;
            }
        }
    }
    return res;
}

vector<vector<ll>> mat_pow_mod(vector<vector<ll>> &x, ll n, ll m) {
    vector<vector<ll>> y = x;
    vector<vector<ll>> res(x.size(), vector<ll>(x[0].size()));
    for (ll i = 0; i < (ll)res.size(); ++i) {
        res[i][i] = 1;
    }

    while (n > 0) {
        if (n & 1) res = mat_mul_mod(res, y, m);
        y = mat_mul_mod(y, y, m);
        n >>= 1;
    }

    return res;
}



int main() {
    ll k, m;
    cin >> k >> m;
    vector<ll> c(k), l(k);
    for (ll i = 0; i < k; ++i) {
        cin >> c[i] >> l[i];
    }

    ll mod = m * 10007;

    vector<vector<ll>> mat = { {10, 1}, {0, 1} };

    ll ans = 0;
    for (ll i = 0; i < k; ++i) {
        ans = ans * atcoder::pow_mod(10, l[i], mod) % mod;
        // (Rn, 1) = ((10, 1), (0, 1))^n (0, 1)
        ans += mat_pow_mod(mat, l[i], mod)[0][1] * c[i] % mod;
        ans %= mod;
    }

    cout << ans / m << endl;

    return 0;
}