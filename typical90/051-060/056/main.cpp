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
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> dp(n, vector<int>(s + 1));
    if (a[0] <= s) dp[0][a[0]] = 1;
    if (b[0] <= s) dp[0][b[0]] = 2;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (j >= a[i] && dp[i - 1][j - a[i]] > 0) dp[i][j] = 1;
            if (j >= b[i] && dp[i - 1][j - b[i]] > 0) dp[i][j] = 2;
        }
    }

    if (dp[n - 1][s] == 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    string ans = "";
    int j = s;
    for (int i = n - 1; i >= 0; --i) {
        if (dp[i][j] == 1) {
            ans = 'A' + ans;
            j -= a[i];
        } else {
            ans = 'B' + ans;
            j -= b[i];
        }
    }

    cout << ans << endl;

    return 0;
}