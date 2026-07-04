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
    string n;
    cin >> n;
    ll m = (ll)n.size();

    // dp[i][j][k][l]: i桁目まででmod3=jで含む文字パターンがkで上からi桁がNと一致すればl=1
    vector<vector<vector<vector<mint>>>> dp(m+1, vector<vector<vector<mint>>>(3, vector<vector<mint>>(1<<10, vector<mint>(2))));
    dp[0][0][0][1] = 1;
    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < 3; ++j) {
            // k > 0
            for (ll k = 1; k < 1024; ++k) {
                for (ll c = 0; c < 10; ++c) {
                    dp[i+1][(j+c)%3][k | (1LL << c)][0] += dp[i][j][k][0];
                }
                ll digit = n[i] - '0';
                for (ll c = 0; c < digit; ++c) {
                    dp[i+1][(j+c)%3][k | (1LL << c)][0] += dp[i][j][k][1];
                }
                dp[i+1][(j + digit)%3][k | (1LL << digit)][1] += dp[i][j][k][1];
            }
            // k = 0
            {
                for (ll c = 1; c < 10; ++c) {
                    dp[i+1][(j+c)%3][(1LL << c)][0] += dp[i][j][0][0];
                }
                ll digit = n[i] - '0';
                for (ll c = 1; c < digit; ++c) {
                    dp[i+1][(j+c)%3][(1LL << c)][0] += dp[i][j][0][1];
                }
                if (digit > 0) dp[i+1][(j + digit)%3][(1LL << digit)][1] += dp[i][j][0][1];
                dp[i+1][j][0][0] += dp[i][j][0][0] + dp[i][j][0][1];
            }
        }
    }

    mint ans = 0;
    // 3の倍数のみ
    for (ull k = 0; k < 1024ULL; ++k) {
        if (k & (1ULL << 3)) continue;
        if (popcount(k) == 3 || popcount(k) == 0) continue;
        ans += dp[m][0][k][0] + dp[m][0][k][1];
    }
    // '3'が含まれるのみ
    for (ull k = 0; k < 1024ULL; ++k) {
        if (k & (1ULL << 3)) {
            if (popcount(k) == 3 || popcount(k) == 0) continue;
            ans += dp[m][1][k][0] + dp[m][1][k][1] + dp[m][2][k][0] + dp[m][2][k][1];
        }
    }
    // 3種類のみ
    for (ull k = 0; k < 1024ULL; ++k) {
        if (popcount(k) == 3) {
            if (k & (1ULL << 3)) continue;
            ans += dp[m][1][k][0] + dp[m][1][k][1] + dp[m][2][k][0] + dp[m][2][k][1];
        }
    }
    cout << ans.val() << endl;

    return 0;
}