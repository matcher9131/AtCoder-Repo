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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i][j]: i匹目までを倒すか逃がすかしてj=今まで倒した数 % 2となるときに得る経験値の最大値
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    dp[0][0] = 0;
    dp[0][1] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            ll x = dp[i-1][j];
            ll y = dp[i-1][!j] == -1 ? -1 : dp[i-1][!j] + a[i - 1] * (j == 0 ? 2 : 1);
            dp[i][j] = x == -1 ?
                y == -1 ? -1 : y
                : y == -1 ? x : max(x, y);
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}