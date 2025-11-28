#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;

// 行列の積(mint)
vector<vector<mint>> mat_mul_mod(vector<vector<mint>> &x, vector<vector<mint>> &y) {
    assert(x[0].size() == y.size());
    vector<vector<mint>> res(x.size(), vector<mint>(y[0].size()));
    for (ll i = 0; i < (ll)x.size(); ++i) {
        for (ll j = 0; j < (ll)y.size(); ++j) {
            for (ll k = 0; k < (ll)y[0].size(); ++k) {
                res[i][j] += x[i][k] * y[k][j];
            }
        }
    }
    return res;
}

// 行列の累乗(mint)
vector<vector<mint>> mat_pow_mod(vector<vector<mint>> &x, ll n) {
    vector<vector<mint>> res(x.size(), vector<mint>(x[0].size()));
    for (ll i = 0; i < (ll)res.size(); ++i) {
        res[i][i] = 1;
    }

    while (n > 0) {
        if (n & 1) res = mat_mul_mod(res, x);
        x = mat_mul_mod(x, x);
        n >>= 1;
    }

    return res;
}

// 行列の積（各要素はmod m）
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

// 行列の累乗（各要素はmod m）
vector<vector<ll>> mat_pow_mod(vector<vector<ll>> &x, ll n, ll m) {
    vector<vector<ll>> res(x.size(), vector<ll>(x[0].size()));
    for (ll i = 0; i < (ll)res.size(); ++i) {
        res[i][i] = 1;
    }

    while (n > 0) {
        if (n & 1) res = mat_mul_mod(res, x, m);
        x = mat_mul_mod(x, x, m);
        n >>= 1;
    }

    return res;
}

