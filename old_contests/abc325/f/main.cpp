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

constexpr int INF = 1e8;
constexpr ll INF2 = 1e18;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    int l1, l2, c1, c2, k1, k2;
    cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;

    // dp[i][j]: 区間iまで見てセンサー1をj個使うときの必要なセンサー2の個数の最小値
    vector<vector<int>> dp(n + 1, vector<int>(k1 + 1, INF));
    fill(dp[0].begin(), dp[0].end(), 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k1; ++j) {
            for (int k = 0; k <= k1 - j; ++k) {
                int rest = d[i] - k * l1;
                if (rest < 0) rest = 0;
                dp[i + 1][j + k] = min(dp[i + 1][j + k], dp[i][j] + (rest + l2 - 1) / l2);
            }
        }
    }

    ll ans = INF2;
    for (int j = 0; j <= k1; ++j) {
        if (dp[n][j] <= k2) {
            ans = min(ans, j * (ll)c1 + dp[n][j] * (ll)c2);
        }
    }
    cout << (ans == INF2 ? -1 : ans) << endl;

    return 0;
}