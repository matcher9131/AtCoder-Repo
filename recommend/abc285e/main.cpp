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
    vector<ll> s(n+1);
    for (int i = 1; i <= n; ++i) {
        ll ai;
        cin >> ai;
        s[i] = s[i-1] + ai;
    }

    // dp[i][j]: i日目まで見て最後の休日がj日目のときの週の生産量最大値
    vector<vector<ll>> dp(n, vector<ll>(n));
    dp[0][0] = s[n/2] + s[(n-1)/2];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[i-1][j] == 0) continue;
            dp[i][j] = dp[i-1][j];

            int l = i - (i - j - 1) / 2;
            int r = i + (n - i - 1) / 2;
            ll oldSum = s[(n-j)/2] + s[(n-j-1)/2] - s[l-1-j] - s[n-1-r];
            ll newSum = s[i-l] + s[r-i];
            dp[i][i] = max(dp[i][i], dp[i-1][j] - oldSum + newSum);
        }
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;

    return 0;
}