#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

vector<vector<mint>> mat_mul_mod(vector<vector<mint>> x, vector<vector<mint>> y) {
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

vector<vector<mint>> mat_pow_mod(vector<vector<mint>> x, ll n) {
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

int main() {
    ll n;
    cin >> n;
    ll w = to_string(n).size();

    vector<vector<mint>> a{{mint(10).pow(w), 1}, {0, 1}};
    auto b = mat_pow_mod(a, n-1);
    cout << ((b[0][0] + b[0][1]) * n).val() << endl;

    return 0;
}