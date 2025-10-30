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
    vector<vector<ll>> x(2), y(2);
    for (ll i = 0; i < n; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        ll k = (xi+yi) % 2;
        x[k].push_back(xi+yi);
        y[k].push_back(xi-yi);
    }
    for (ll k = 0; k < 2; ++k) {
        sort(x[k].begin(), x[k].end());
        sort(y[k].begin(), y[k].end());
    }

    ll ans = 0;
    for (ll k = 0; k < 2; ++k) {
        ll sum = 0;
        for (ll i = 0; i < (ll)x[k].size(); ++i) {
            ans += i * x[k][i] - sum;
            sum += x[k][i];
        }
        sum = 0;
        for (ll i = 0; i < (ll)y[k].size(); ++i) {
            ans += i * y[k][i] - sum;
            sum += y[k][i];
        }
    }
    cout << ans/2 << endl;

    return 0;
}