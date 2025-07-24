#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;
using ll = long long;
constexpr ll INF = 1e16;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    vector<vector<ll>> g(h, vector<ll>(w));
    for (ll i = 0; i < k; ++i) {
        ll ri, ci, vi;
        cin >> ri >> ci >> vi;
        --ri;
        --ci;
        g[ri][ci] = vi;
    }

    // dp[i][j][k]: マス(1,1)から(i,j)まで移動してきて現在の行でk個アイテムを拾っている状態での価値の合計の最大値
    vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(4)));
    if (g[0][0] > 0) {
        dp[0][0][1] = g[0][0];
    }
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            for (ll k = 0; k < 4; ++k) {
                if (j >= 1) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                    if (k >= 1 && g[i][j] > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + g[i][j]);
                }
                if (i >= 1) {
                    dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][k]);
                    if (g[i][j] > 0) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][k] + g[i][j]);
                }
            }
        }
    }

    cout << *max_element(dp[h-1][w-1].begin(), dp[h-1][w-1].end()) << endl;

    return 0;
}