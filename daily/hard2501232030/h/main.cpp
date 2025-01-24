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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<mint> answers(n + 1);
    answers[1] = n;
    for (int i = 0; i < n - 1; ++i) {
       // dp[l][j]: 初項a[i], 項数l, 末項a[j]となるような等差数列の選び方の場合の数
        vector<vector<mint>> dp(n + 1, vector<mint>(n));
        for (int j = i + 1; j < n; ++j) {
            dp[2][j] = 1;
        }
        // 配るDP
        for (int l = 2; l < n; ++l) {
            for (int j = i; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (a[k] == a[j] + (a[j] - a[i]) / (l - 1)) {
                        dp[l+1][k] += dp[l][j];
                    }
                }
            }
        }
        // 集計
        for (int l = 2; l <= n; ++l) {
            for (int j = 0; j < n; ++j) {
                answers[l] += dp[l][j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << answers[i].val() << " \n"[i == n];
    }

    return 0;
}