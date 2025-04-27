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
#include <atcoder/segtree>
using namespace std;
using ll = long long;


int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    int m = 1e6;
    vector<int> c(m+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i]];
    }

    if (d == 0) {
        cout << n - count_if(c.begin(), c.end(), [](int x) { return x > 0; }) << endl;
        return 0;
    }

    int ans = 0;
    for (int r = 0; r < d; ++r) {
        int qMax = (m - r) / d;
        vector<int> dp(qMax + 1);
        for (int q = 0; q < qMax; ++q) {
            dp[q+1] = min(dp[q] + c[d*(q+1)+r], (q > 0 ? dp[q-1] : 0) + c[d*q+r]);
        }
        ans += dp[qMax];
    }

    cout << ans << endl;
    return 0;
}