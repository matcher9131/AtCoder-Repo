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
    vector<string> g(h);
    for (ll i = 0; i < h; ++i) {
        cin >> g[i];
    }

    vector<vector<ll>> s(h+1, vector<ll>(w+1));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + (g[i][j] == '1');
        }
    }

    auto getCount = [&](vector<pair<ll, ll>> &seg) -> ll {
        vector<ll> c(seg.size());
        ll cw = 0;
        for (ll j = 1; j <= w; ++j) {
            for (ll si = 0; si < (ll)seg.size(); ++si) {
                auto [u, d] = seg[si];
                ll cnt = s[d][j] - s[u][j] - s[d][j-1] + s[u][j-1];
                if (cnt > k) return INF;
                c[si] += cnt;
            }
            if (any_of(c.begin(), c.end(), [&](ll val) { return val > k; })) {
                ++cw;
                for (ll si = 0; si < (ll)seg.size(); ++si) {
                    auto [u, d] = seg[si];
                    c[si] = s[d][j] - s[u][j] - s[d][j-1] + s[u][j-1];
                }
            }
        }
        return (ll)seg.size() - 1 + cw;
    };

    ll ans = INF;
    for (ull bit = 0; bit < (1ULL<<(h-1)); ++bit) {
        vector<pair<ll, ll>> seg;
        ll prev = 0;
        for (ll i = 0; i < h; ++i) {
            if (bit & (1ULL << i)) {
                seg.emplace_back(prev, i+1);
                prev = i+1;
            }
        }
        seg.emplace_back(prev, h);
        chmin(ans, getCount(seg));
    }
    cout << ans << endl;

    return 0;
}