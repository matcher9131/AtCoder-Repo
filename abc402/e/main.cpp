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

    // dp[i][j][k]: 解けた問題の集合がiで支払った金額がjになる確率
    vector<vector<double>> dp(1 << n, vector<double>(x + 1));
    dp[0][0] = 1;
    for (int j = 0; j <= x; ++j) {
        for (int bit = 0; bit < 1 << n; ++bit) {
            for (int i = 0; i < n; ++i) {
                if (bit & (1 << i)) continue;
                if (j + c[i] > x) continue;
                dp[bit][j + c[i]] += dp[bit][j] * (1.0 - p[i] / 100.0);
                dp[bit | (1 << i)][j + c[i]] += dp[bit][j] * p[i] / 100.0;
            }
        }
    }

    double ans = 0;
    for (int bit = 0; bit < 1 << n; ++bit) {
        int score = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) score += s[i];
        }
        double prob = 0;
        for (int j = x; j >= 0; --j) {
            if (dp[bit][j] > 0) {
                prob = dp[bit][j];
                break;
            }
        }
        
        ans += score * prob;
    }

    cout << ans << endl;
    return 0;
}