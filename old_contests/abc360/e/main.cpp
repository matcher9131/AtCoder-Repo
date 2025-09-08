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
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    mint nInv = (mint)1 / n;

    // k回操作後に黒いボールが最も左にある確率
    vector<mint> dp(k + 1);
    dp[0] = 1;
    for (int i = 1; i <= k; ++i) {
        dp[i] = dp[i-1] * ((1 - nInv) * (1 - nInv) + nInv * nInv) + (1 - dp[i-1]) * 2 * nInv * nInv;
    }

    mint ans = dp[k] + (1 - dp[k]) / (n - 1) * ((mint)n * (n + 1) / 2 - 1);
    cout << ans.val() << endl;

    return 0;
}