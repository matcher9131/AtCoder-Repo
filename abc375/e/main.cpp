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

constexpr int INF = 1e6;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sum += b[i];
    }

    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    int max = sum / 3;

    // dp[i][x][y]: i人目まで見て各チームの強さがx, y, zになるために必要な最小の移籍人数
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(max + 1, vector<int>(max + 1, INF)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int team = a[i - 1];
        int power = b[i - 1];
        for (int x = 0; x <= max; ++x) {
            for (int y = 0; y <= max; ++y) {
                // チーム1
                if (x - power >= 0) {
                    dp[i][x][y] = min(dp[i][x][y], dp[i - 1][x - power][y] + (team == 1 ? 0 : 1));
                }
                // チーム2
                if (y - power >= 0) {
                    dp[i][x][y] = min(dp[i][x][y], dp[i - 1][x][y - power] + (team == 2 ? 0 : 1));
                }
                // チーム3
                dp[i][x][y] = min(dp[i][x][y], dp[i - 1][x][y] + (team == 3 ? 0 : 1));
            }
        }
    }

    int ans = dp[n][max][max];
    cout << (ans >= INF ? -1 : ans) << endl;

    return 0;
}