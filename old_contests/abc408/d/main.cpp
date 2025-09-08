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

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<pair<int, int>> seg;
    int l = -1;
    for (int i = 0; i < n; ++i) {
        if (l == -1 && s[i] == '1') {
            l = i;
        } else if (l != -1 && s[i] == '0') {
            seg.emplace_back(l, i);
            l = -1;
        }
    }
    if (l != -1) {
        seg.emplace_back(l, n);
    }

    int m = seg.size();
    if (m == 0) {
        cout << 0 << endl;
        return;
    }

    // dp[i][j]: i番目の'1'の区間をj=0: そこまですべて消す, j=1: そこから右すべて消す, j=2: 残すのに必要な操作の最小値
    vector<vector<int>> dp(m, vector<int>(3, 1e8));
    dp[0][0] = seg[0].second - seg[0].first;
    dp[0][1] = seg[0].second - seg[0].first;
    dp[0][2] = 0;
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0] + seg[i].second - seg[i].first;
        dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + seg[i].second - seg[i].first;
        dp[i][2] = min(dp[i-1][0], dp[i-1][2] + seg[i].first - seg[i-1].second);
    }

    cout << *min_element(dp[m-1].begin(), dp[m-1].end()) << endl;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}