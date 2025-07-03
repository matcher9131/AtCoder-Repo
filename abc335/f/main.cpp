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

constexpr int BORDER = 450;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<mint> dp(n);
    dp[0] = 1;
    vector<vector<mint>> dp2(BORDER+1, vector<mint>(BORDER));

    for (int i = 0; i < n; ++i) {
        for (int d = 1; d <= BORDER; ++d) {
            dp[i] += dp2[d][i%d];
        }

        if (a[i] > BORDER) {
            for (int j = i + a[i]; j < n; j += a[i]) {
                dp[j] += dp[i];
            }
        } else {
            dp2[a[i]][i % a[i]] += dp[i];
        }
    }

    mint ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[i];
    }
    cout << ans.val() << endl;

    return 0;
}