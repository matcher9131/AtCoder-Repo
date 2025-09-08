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

inline const string& shorter(const string &x, const string &y) {
    return x.empty() ? y
        : y.empty() ? x
        : y.size() < x.size() ? y : x;
}

int main() {
    int n;
    cin >> n;

    // i: number, j: factorized
    vector<vector<string>> dp(n+1, vector<string>(2));
    auto getShortestAddition = [&](int x, int y) {
        return shorter(dp[x][0], dp[x][1]) + "+" + shorter(dp[y][0], dp[y][1]);
    };
    auto getShortestMultiplication = [&](int x, int y) {
        string x0 = "(" + dp[x][0] + ")";
        string y0 = "(" + dp[y][0] + ")";
        return shorter(x0, dp[x][1]) + "*" + shorter(y0, dp[y][1]);
    };

    for (int i = 1; i <= n; ++i) {
        if (i == 1 || i == 11 || i == 111 || i == 1111) {
            dp[i][0] = dp[i][1] = to_string(i);
        } else {
            for (int j = 1; j <= i / 2; ++j) {
                dp[i][0] = shorter(dp[i][0], getShortestAddition(j, i-j));
            }
            for (int j = 2; j * j <= i; ++j) {
                if (i % j != 0) continue;
                dp[i][1] = shorter(dp[i][1], getShortestMultiplication(j, i/j));
            }
        }
    }

    cout << shorter(dp[n][0], dp[n][1]) << endl;

    return 0;
}