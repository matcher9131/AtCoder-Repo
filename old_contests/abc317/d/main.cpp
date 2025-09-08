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

constexpr ll INF = 1e12;

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n), z(n);
    ll allz = 0;
    ll sumz = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
        allz += z[i];
        if (x[i] > y[i]) sumz += z[i];
    }

    ll rest = (allz + 1) / 2 - sumz;
    if (rest <= 0) {
        cout << 0 << endl;
        return 0;
    }

    // dp[i][j]: i番目までの選挙区で高橋派が全体でj議席を獲得するのに必要な最低の鞍替え人数
    vector<vector<ll>> dp(n + 1, vector<ll>(allz + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= allz; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j < z[i - 1]) continue;
            if (x[i - 1] > y[i - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - z[i - 1]]);
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - z[i - 1]] + (y[i - 1] - x[i - 1] + 1) / 2);
            }
        }
    }

    ll answer = *min_element(dp[n].begin() + ((allz + 1) / 2), dp[n].end());

    cout << answer << endl;

    return 0;
}
