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
    int n, x;
    cin >> n >> x;
    vector<int> s(n), c(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> c[i] >> p[i];
    }

    // dp[i][j]: 解けた問題の集合がiで支払った金額がjのときの得点期待値の最大値
    vector<vector<double>> dp(1 << n, vector<double>(x + 1));
    for (int bit = 0; bit < 1 << n; ++bit) {
        for (int j = 0; j <= x; ++j) {
            for (int i = 0; i < n; ++i) {
                if ((bit & (1 << i)) == 0) continue;
                if (j < c[i]) continue;
                dp[bit][j] = max(dp[bit][j], (s[i] + dp[bit ^ (1 << i)][j - c[i]]) * p[i] / 100.0 + dp[bit][j - c[i]] * (1.0 - p[i] / 100.0));
            }
        }
    }

    double ans = 0;
    for (int bit = 0; bit < 1 << n; ++bit) {
        ans = max(ans, *max_element(dp[bit].begin(), dp[bit].end()));
    }

    cout << setprecision(15) << ans << endl;
    return 0;
}