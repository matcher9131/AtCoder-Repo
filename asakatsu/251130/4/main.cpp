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
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<vector<ll>> cr(h, vector<ll>(w)), cc(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        ll l = 0;
        while (true) {
            while (l < w && s[i][l] == '#') ++l;
            if (l == w) break;
            ll r = l;
            while (r < w && s[i][r] == '.') ++r;
            for (ll j = l; j < r; ++j) {
                cr[i][j] = r-l;
            }
            if (r == w) break;
            l = r;
        }
    }
    for (ll j = 0; j < w; ++j) {
        ll u = 0;
        while (true) {
            while (u < h && s[u][j] == '#') ++u;
            if (u == h) break;
            ll d = u;
            while (d < h && s[d][j] == '.') ++d;
            for (ll i = u; i < d; ++i) {
                cc[i][j] = d-u;
            }
            if (d == h) break;
            u = d;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            chmax(ans, cr[i][j] + cc[i][j] - 1);
        }
    }
    cout << ans << endl;

    return 0;
}