#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    int n = 9;
    vector<vector<int>> a(n, vector<int>(n));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }

    ll bitAll = (1 << n) - 1;
    for (ll i = 0; i < n; ++i) {
        ll bit = 0;
        for (ll j = 0; j < n; ++j) {
            bit |= 1 << a[i][j];
        }
        if (bit != bitAll) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (ll j = 0; j < n; ++j) {
        ll bit = 0;
        for (ll i = 0; i < n; ++i) {
            bit |= 1 << a[i][j];
        }
        if (bit != bitAll) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (ll bi = 0; bi < 3; ++bi) {
        for (ll bj = 0; bj < 3; ++bj) {
            ll bit = 0;
            for (ll i = 0; i < 3; ++i) {
                for (ll j = 0; j < 3; ++j) {
                    bit |= 1 << a[3*bi+i][3*bj+j];
                }
            }
            if (bit != bitAll) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}