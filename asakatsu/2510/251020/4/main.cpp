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
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> b(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        string si;
        cin >> si;
        for (ll j = 0; j < w; ++j) {
            b[i][j] = si[j] - '0';
        }
    }

    vector<vector<ll>> a(h, vector<ll>(w));
    for (ll i = 1; i < h-1; ++i) {
        for (ll j = 1; j < w-1; ++j) {
            a[i][j] = b[i-1][j];
            b[i-1][j] = 0;
            b[i+1][j] -= a[i][j];
            b[i][j-1] -= a[i][j];
            b[i][j+1] -= a[i][j];
        }
    }

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}