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
    int n, hp, mp;
    cin >> n >> hp >> mp;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    // dp[i][j]: i番目まで倒して残りMPがjのときの残り体力の最大値
    vector<vector<int>> dp(n+1, vector<int>(mp+1, -1));
    dp[0][mp] = hp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= mp; ++j) {
            if (dp[i][j] >= a[i]) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] - a[i]);
            }
            if (j >= b[i]) {
                dp[i+1][j-b[i]] = max(dp[i+1][j-b[i]], dp[i][j]);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= mp; ++j) {
        int tmpAns = 0;
        for (int i = 0; i <= n; ++i) {
            if (dp[i][j] >= 0) tmpAns = i;
        }
        ans = max(ans, tmpAns);
    }

    cout << ans << endl;

    return 0;
}