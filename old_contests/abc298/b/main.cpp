#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> b(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }

    auto rotated = [&](vector<vector<ll>> &original) {
        vector<vector<ll>> res(n, vector<ll>(n));
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                res[i][j] = original[n-1-j][i];
            }
        }
        return res;
    };

    auto isOK = [&](vector<vector<ll>> &x, vector<vector<ll>> &y) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (x[i][j] == 1 && y[i][j] == 0) return false;
            }
        }
        return true;
    };

    for (ll ri = 0; ri < 4; ++ri) {
        if (isOK(a, b)) {
            cout << "Yes" << endl;
            return 0;
        }
        a = rotated(a);
    }

    cout << "No" << endl;
    return 0;
}