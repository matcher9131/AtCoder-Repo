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

    // dp[i][k][d]: 末項がa[i]で項数がkで公差dの等差数列の個数
    vector<vector<unordered_map<int, mint>>> dp(n, vector<unordered_map<int, mint>>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = a[j] - a[i];
            ++dp[j][2][d];
        }
    }

    for (int j = 1; j < n; ++j) {
        for (int k = 2; k <= n; ++k) {
            for (const auto& [d, _] : dp[j][k]) {
                for (int j2 = j + 1; j2 < n; ++j2) {
                    if (a[j2] - a[j] == d) {
                        dp[j2][k+1][d] += dp[j][k][d];
                    }
                }
            }
        }
    }

    vector<mint> ans(n + 1);
    ans[1] = n;
    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (const auto& [_, c]: dp[i][k]) {
                ans[k] += c;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i].val() << " \n"[i == n];
    }

    return 0;
}