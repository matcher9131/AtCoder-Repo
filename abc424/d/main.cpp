#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

inline bool isBlack(ll board, ll i) {
    return board & (1ULL << i);
}

void solve() {
    ll h, w;
    cin >> h >> w;
    ull master = 0;
    for (ll i = 0; i < h; ++i) {
        string si;
        cin >> si;
        for (ll j = 0; j < w; ++j) {
            if (si[j] == '#') master |= 1ULL << (i*w+j);
        }
    }
    ull mask = (1ULL << (w+1)) - 1ULL;

    vector<vector<ll>> dp(h*w+1, vector<ll>(1<<(w+1), INF));
    dp[w+1][master & mask] = 0;
    for (ll i = w+1; i < h*w; ++i) {
        ull masked = (master >> (i-w-1)) & mask;
        for (ull bit = 0; bit < 1ULL << (w+1); ++bit) {
            if ((masked & bit) != bit) continue;
            // 白
            dp[i+1][bit>>1] = min(dp[i+1][bit>>1], dp[i][bit] + (isBlack(master, i) ? 1 : 0));
            // 黒
            if (isBlack(master, i) && (i%w == 0 || !isBlack(bit, 0) || !isBlack(bit, 1) || !isBlack(bit, w))) {
                dp[i+1][(bit>>1) | (1ULL<<w)] = min(dp[i+1][(bit>>1) | (1ULL<<w)], dp[i][bit]);
            }
        }
    }

    cout << *min_element(dp[h*w].begin(), dp[h*w].end()) << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}