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

constexpr ll INF = 1e18;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int bm = 40;
    vector<int> one(bm);
    for (int bi = 0; bi < bm; ++bi) {
        for (int i = 0; i < n; ++i) {
            if (a[i] & (1LL << bi)) {
                ++one[bi];
            }
        }
    }

    // dp[i][j]: i桁目まで決めて確定部分がKより小さいかどうかをjとしたときの解の最大値
    vector<vector<ll>> dp(bm + 1, vector<ll>(2, -INF));
    dp[bm][0] = 0;
    for (int bi = bm - 1; bi >= 0; --bi) {
        for (int less = 0; less < 2; ++less) {
            if (dp[bi+1][less] < 0) continue;
            // 0を選ぶ
            bool newLess = less || (k & (1LL << bi));
            dp[bi][newLess] = max(dp[bi][less], dp[bi+1][less] + (1LL << bi) * one[bi]);
            // 1を選ぶ
            if ((k & (1LL << bi)) || less) {
                dp[bi][less] = max(dp[bi][less], dp[bi+1][less] + (1LL << bi) * (n - one[bi]));
            }
        }
    }

    cout << *max_element(dp[0].begin(), dp[0].end()) << endl;

    return 0;
}