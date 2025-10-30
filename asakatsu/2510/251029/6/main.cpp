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
    string s;
    cin >> s;

    vector<vector<optional<mint>>> dpc(2*n, vector<optional<mint>>(2*n+1));
    vector<vector<optional<mint>>> dps(2*n, vector<optional<mint>>(2*n+1));
    if (s[0] != '-') {
        dpc[0][n+1] = 1;
        dps[0][n+1] = 0;
    }
    if (s[0] != '+') {
        dpc[0][n-1] = 1;
        dps[0][n-1] = 0;
    }
    for (ll i = 1; i < 2*n; ++i) {
        if (s[i] != '-') {
            for (ll j = 1; j < 2*n+1; ++j) {
                if (!dpc[i-1][j-1].has_value()) continue;
                dpc[i][j] = dpc[i][j].value_or(0) + dpc[i-1][j-1].value();
                dps[i][j] = dps[i][j].value_or(0) + dps[i-1][j-1].value() + dpc[i-1][j-1].value() * abs(j-1-n);
            }
        }
        if (s[i] != '+') {
            for (ll j = 0; j < 2*n; ++j) {
                if (!dpc[i-1][j+1].has_value()) continue;
                dpc[i][j] = dpc[i][j].value_or(0) + dpc[i-1][j+1].value();
                dps[i][j] = dps[i][j].value_or(0) + dps[i-1][j+1].value() + dpc[i-1][j+1].value() * abs(j+1-n);
            }
        }
    }

    assert(dps[2*n-1][n].has_value());
    cout << dps[2*n-1][n].value().val() << endl;

    return 0;
}