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
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    // dp[i][j]: 使われた単語の集合がiで最後に選ばれた単語がjのときの勝敗（1: 先手勝ち, -1: 後手勝ち）
    vector<vector<int>> dp(1 << n, vector<int>(n+1));

    function<int(int, int, int)> dfs = [&](int pattern, int last, int turn) -> int {
        if (dp[pattern][last] != 0) return dp[pattern][last];
        for (int i = 0; i < n; ++i) {
            if (pattern & (1 << i)) continue;
            if (last == n || s[i][0] == s[last].back()) {
                int result = dfs(pattern | (1 << i), i, -turn);
                if (result == turn) return dp[pattern][last] = result;
            }
        }
        return dp[pattern][last] = -turn;
    };
    int ans = dfs(0, n, 1);

    cout << (ans == 1 ? "First" : "Second") << endl;
    return 0;
}