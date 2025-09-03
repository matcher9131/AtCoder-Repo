#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e16;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    --k;

    auto isValidRow = [&](ll bit) -> bool {
        for (ll j = 0; j < w-2; ++j) {
            if (((bit >> j) & 0b11) == 0b11) return false;
        }
        return true;
    };

    // i行目(1-indexed)までで左端からの行き先がjになるような線の引き方
    vector<vector<mint>> dp(h+1, vector<mint>(w));
    dp[0][0] = 1;
    for (ll i = 1; i <= h; ++i) {
        for (ll bit = 0; bit < 1LL << (w-1); ++bit) {
            if (!isValidRow(bit)) continue;
            for (ll j = 0; j < w; ++j) {
                if (j > 0 && (bit & (1LL << (j-1)))) {
                    dp[i][j] += dp[i-1][j-1];
                } else if (j < w-1 && (bit & (1LL << j))) {
                    dp[i][j] += dp[i-1][j+1];
                } else {
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
    }

    cout << dp[h][k].val() << endl;

    return 0;
}