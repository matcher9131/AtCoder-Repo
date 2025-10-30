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
    ll h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    auto rotate = [&](ll i, ll j) -> pair<ll, ll> {
        return { i+j, h-1-i+j };
    };

    vector<vector<bool>> s2(h+w-1, vector<bool>(h+w-1));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == 'x') {
                auto [x, y] = rotate(i, j);
                s2[x][y] = true;
            }
        }
    }

    vector<vector<ll>> sum(h+w, vector<ll>(h+w));
    for (ll x = 0; x < h+w-1; ++x) {
        for (ll y = 0; y < h+w-1; ++y) {
            sum[x+1][y+1] = sum[x][y+1] + sum[x+1][y] - sum[x][y] + s2[x][y];
        }
    }

    ll ans = 0;
    for (ll i = k-1; i <= h-k; ++i) {
        for (ll j = k-1; j <= w-k; ++j) {
            auto [x, y] = rotate(i, j);
            // [x1, x2)×[y1, y2)
            ll x1 = x - (k-1), x2 = x + k;
            ll y1 = y - (k-1), y2 = y + k;
            if (sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1] == 0) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}