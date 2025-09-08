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

constexpr int INF = 1e7;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    // dp[i][j][k]: i番目(1-indexed)の料理まで見たときに食べた品数がjで甘さの合計がkになるときのしょっぱさの最小値
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(x + 1, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k <= x; ++k) {
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                if (k + a[i] <= x) {
                    dp[i+1][j+1][k+a[i]] = min(dp[i+1][j+1][k+a[i]], dp[i][j][k] + b[i]);
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= x; ++k) {
            if (dp[n][j][k] <= y) {
                ans = max(ans, j);
            }
        }
    }
    if (ans < n) ++ans;

    cout << ans << endl;

    return 0;
}