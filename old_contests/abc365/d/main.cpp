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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] == 'R' ? 0 : s[i] == 'P' ? 1 : 2;
    }

    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][a[0]] = 0;
    dp[0][(a[0] + 1) % 3] = 1;
    for (int i = 1; i < n; ++i) {
        if (dp[i-1][(a[i] + 1) % 3] != -1) dp[i][a[i]] = max(dp[i][a[i]], dp[i-1][(a[i] + 1) % 3]);
        if (dp[i-1][(a[i] + 2) % 3] != -1) dp[i][a[i]] = max(dp[i][a[i]], dp[i-1][(a[i] + 2) % 3]);
        if (dp[i-1][a[i]] != -1) dp[i][(a[i] + 1) % 3] = max(dp[i][(a[i] + 1) % 3], dp[i-1][a[i]] + 1);
        if (dp[i-1][(a[i] + 2) % 3] != -1) dp[i][(a[i] + 1) % 3] = max(dp[i][(a[i] + 1) % 3], dp[i-1][(a[i] + 2) % 3] + 1);
        dp[i][(a[i] + 2) % 3] = -1;
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;

    return 0;
}