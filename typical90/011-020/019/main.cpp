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

constexpr ll INF = 1e18;

int main() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(2 * n, vector<ll>(2 * n, INF));
    for (int i = 0; i < 2 * n - 1; ++i) {
        dp[i][i + 1] = abs(a[i + 1] - a[i]);
    }

    for (int d = 3; d < 2 * n; d += 2) {
        for (int l = 0; l < 2 * n - d; ++l) {
            int r = l + d;
            for (int i = l; i < r; ++i) {
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + abs(a[l] - a[r]));
            }
        }
    }

    cout << dp[0][2 * n - 1] << endl;

    return 0;
}