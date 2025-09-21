#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    
    bool flipped = h < w;
    if (flipped) swap(h, w);
    vector<vector<ll>> dp(h*w+1, vector<ll>(1 << (w+1)));
    vector<vector<ll>> prev(h*w+1, vector<ll>(1 << (w+1)));

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            ll cellNo = i*w + j;
            for (ull bit = 0; bit < 1ULL<<(w+1); ++bit) {
                ll cp = 0, cw = 0;
                if (i > 0 && j > 0) ++((bit & 1ULL) ? cp : cw);
                if (i > 0) ++((bit & 2ULL) ? cp : cw);
                if (i > 0 && j < w-1) ++((bit & 4ULL) ? cp : cw);
                if (j > 0) ++((bit & (1ULL<<w)) ? cp : cw);
                if (dp[cellNo][bit] + cp * b > dp[cellNo+1][bit>>1]) {
                    dp[cellNo+1][bit>>1] = dp[cellNo][bit] + cp * b;
                    prev[cellNo+1][bit>>1] = bit;
                }
                if (dp[cellNo][bit] + a + cw * b > dp[cellNo+1][(bit>>1) | (1ULL<<w)]) {
                    dp[cellNo+1][(bit>>1) | (1ULL<<w)] = dp[cellNo][bit] + a + cw * b;
                    prev[cellNo+1][(bit>>1) | (1ULL<<w)] = bit;
                }
            }
        }
    }

    ull j = max_element(dp[h*w].begin(), dp[h*w].end()) - dp[h*w].begin();
    cout << dp[h*w][j] << endl;

    vector<bool> ans(h*w);
    for (ll i = 0; i < w+1; ++i) {
        if (j & (1ULL << i)) ans[(h-1)*w-1+i] = true;
    }
    j = prev[h*w][j];
    for (ll i = h*w-1; i >= w+1; --i) {
        ans[i-w-1] = j&1;
        j = prev[i][j];
    }

    if (flipped) {
        for (ll j = 0; j < w; ++j) {
            for (ll i = 0; i < h; ++i) {
                cout << (ans[i*w+j] ? '#' : '.');
            }
            cout << endl;
        }
    } else {
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                cout << (ans[i*w+j] ? '#' : '.');
            }
            cout << endl;
        }
    }

    return 0;
}