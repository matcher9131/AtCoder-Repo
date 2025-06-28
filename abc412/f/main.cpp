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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    int n, c;
    cin >> n >> c;
    --c;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (i == c) ++ai;
        a[i] = { ai, i };
    }
    sort(a.begin(), a.end());
    int ci = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i].second == c) {
            ci = i;
            break;
        }
    }

    mint s = -1;
    for (int i = 0; i < n; ++i) {
        s += a[i].first;
    }
    // dp[i] = (1 + ∑_{j=i+1}^{N} a[j]dp[j]/s) / (1 - ∑_{j=1}^{i-1} a[j]/s)
    vector<mint> dp(n);
    mint x = s + 1;
    mint y = 0;
    for (int i = n - 1; i >= 0; --i) {
        x -= a[i].first;
        dp[i] = (1 + y/s) / (1 - x/s);
        y += a[i].first * dp[i];
    }

    cout << dp[ci].val() << endl;
    return 0;
}