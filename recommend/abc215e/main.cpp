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
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'A';
    }

    // dp[i][j][k]: i回目までのコンテストに参加するかどうかを決め、それまで参加したコンテストの種類の集合がjであり、最後に参加したコンテストの種類がkであるような出場の仕方の場合の数（コンテストに参加したことがなければk = 10）
    vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(1024, vector<mint>(10)));
    dp[0][1 << a[0]][a[0]] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 1024; ++j) {
            for (int k = 0; k < 10; ++k) {
                dp[i][j][k] += dp[i - 1][j][k];
                if (k == a[i]) dp[i][j][k] += dp[i - 1][j][k];
            }
            if (!(j & (1 << a[i]))) {
                for (int k = 0; k < 10; ++k) {
                    dp[i][j | (1 << a[i])][a[i]] += dp[i - 1][j][k];
                }
            }
        }
        dp[i][1 << a[i]][a[i]] += 1;
    }

    mint ans = 0;
    for (int j = 0; j < 1024; ++j) {
        for (int k = 0; k < 10; ++k) {
            ans += dp[n - 1][j][k];
        }
    }

    cout << ans.val() << endl;

    return 0;
}