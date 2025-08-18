#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e16;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<vector<mint>> dp(h, vector<mint>(w));
    dp[0][0] = 1;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') continue;
            if (i+1 < h && s[i+1][j] == '.') dp[i+1][j] += dp[i][j];
            if (j+1 < w && s[i][j+1] == '.') dp[i][j+1] += dp[i][j];
        }
    }

    cout << dp[h-1][w-1].val() << endl;

    return 0;
}