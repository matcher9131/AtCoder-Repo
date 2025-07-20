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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        p[i].first = ai;
    }
    for (int i = 0; i < n; ++i) {
        int bi;
        cin >> bi;
        p[i].second = bi;
    }
    sort(p.begin(), p.end());

    mint ans = 0;
    // dp[i][j]: i番目まででBの合計がjになるような場合の数
    vector<vector<mint>> dp(5001, vector<mint>(5001));
    dp[0][0] = 1;
    dp[0][p[0].second] = 1;
    if (p[0].second <= p[0].first) ++ans;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 5001; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j - p[i].second >= 0) {
                dp[i][j] += dp[i-1][j - p[i].second];
                if (j <= p[i].first) ans += dp[i-1][j - p[i].second];
            }
        }
    }

    cout << ans.val() << endl;

    return 0;
}