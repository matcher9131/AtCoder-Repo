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
    vector<vector<ll>> a(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    ll aMin = INF;
    ll aSum = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            aSum += a[i][j];
            chmin(aMin, a[i][j]);
        }
    }

    cout << aSum - h*w*aMin << endl;

    return 0;
}