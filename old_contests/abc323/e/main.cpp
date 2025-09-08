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
    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    // dp[i]: i秒後に曲が流れ始める確率
    int m = x + 1005;
    vector<mint> dp(m);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + t[j] < m) dp[i + t[j]] += dp[i] / n;
        }
    }

    mint ans = 0;
    for (int i = 0; i < t[0]; ++i) {
        if (x - i >= 0) ans += dp[x - i] / n;
    }

    cout << ans.val() << endl;

    return 0;
}