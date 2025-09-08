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
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
void addModTo(int &x, int y) {
    x = (x + y) % MOD;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2 == 1 || s[0] == ')') {
        cout << 0 << endl;
        return 0;
    }
    int m = n / 2;
    // dp[i][j] sのi文字目までで括弧レベルがjになるような文字列の場合の数
    vector<vector<int>> dp(n + 5, vector<int>(m + 5));
    dp[0][1] = 1;
     
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (s[i] == '(') {
                addModTo(dp[i][j + 1], dp[i - 1][j]);
            } else if (s[i] == ')') {
                if (j > 0) addModTo(dp[i][j - 1], dp[i - 1][j]);
            } else {
                addModTo(dp[i][j + 1], dp[i - 1][j]);
                if (j > 0) addModTo(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << dp[n - 1][0] << endl;

    return 0;
}