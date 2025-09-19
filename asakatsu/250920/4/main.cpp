#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w, d;
    cin >> h >> w >> d;
    vector<vector<ll>> a(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if ((i+j) % 2 != d % 2) continue;
            if (i+j > d) break;
            ans = max(ans, a[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}