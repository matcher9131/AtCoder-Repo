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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    // dp[i][j]: i回サイコロを振ってマスjにいる確率
    vector<vector<mint>> dp(k + 1, vector<mint>(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int mi = 1; mi <= m; ++mi) {
                int nj = j + mi;
                if (nj > n) nj = n - (nj - n);
                dp[i + 1][nj] += dp[i][j] / m;
            }
        }
    }

    mint ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += dp[i][n];
    }

    cout << ans.val() << endl;

    return 0;
}