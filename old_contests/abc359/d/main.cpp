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
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> g;

    auto isPalindrome = [&](int x) -> bool {
        for (int bit = 0; bit < k / 2; ++bit) {
            bool l = (x & 1 << bit) > 0;
            bool r = (x & 1 << (k - 1 - bit)) > 0;
            if (l ^ r) return false;
        }
        return true;
    };

    // dp[i][j]: i文字目までで直前k文字がjのときの良い文字列の数
    vector<vector<mint>> dp(n, vector<mint>(1 << k));
    dp[0][0] = k == 1 ? 0
        : s[0] != 'B' ? 1
        : 0;
    dp[0][1] = k == 1 ? 0
        : s[0] != 'A' ? 1
        : 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            if (i >= k - 1 && isPalindrome(j)) continue;
            if (s[i] == 'A' && j % 2 == 1) continue;
            if (s[i] == 'B' && j % 2 == 0) continue;
            dp[i][j] = dp[i-1][j >> 1] + dp[i-1][(j >> 1) | (1 << (k - 1))];
        }
    }

    cout << accumulate(dp[n-1].begin(), dp[n-1].end(), (mint)0).val() << endl;

    return 0;
}