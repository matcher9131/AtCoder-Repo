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

constexpr int MIN = -1e8;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<vector<int>> dp(h, vector<int>(w, MIN));
    function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (dp[i][j] != MIN) return dp[i][j];

        if (i == h - 1 && j == w - 1) return 0;

        int result = MIN;
        if (i < h - 1) {
            result = max(result, -dfs(i+1, j) + (s[i+1][j] == '+' ? 1 : -1));
        }
        if (j < w - 1) {
            result = max(result, -dfs(i, j+1) + (s[i][j+1] == '+' ? 1 : -1));
        }

        dp[i][j] = result;
        return result;
    };

    int ans = dfs(0, 0);
    cout << (ans > 0 ? "Takahashi" : ans < 0 ? "Aoki" : "Draw") << endl;

    return 0;
}