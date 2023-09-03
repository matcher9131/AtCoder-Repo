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
using namespace std;
using ll = long long;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    // dp[i][j][0]: i桁目まで確定していて0以外がj個あり、Nより小さいことが確定している場合の数
    // dp[i][j][1]: i桁目まで確定していて0以外がj個あり、Nより小さいことが確定していない場合の数
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 5, vector<int>(2)));
    dp[0][0][1] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i + 1][s[i] == '0' ? j : j + 1][1] += dp[i][j][1];
            dp[i + 1][j + 1][0] += 9 * dp[i][j][0];
            dp[i + 1][j][0] += dp[i][j][0];
            if (s[i] != '0') {
                dp[i + 1][j + 1][0] += (s[i] - '0' - 1) * dp[i][j][1];
                dp[i + 1][j][0] += dp[i][j][1];
            }
        }
    }

    cout << dp[n][k][0] + dp[n][k][1] << endl;

    return 0;
}