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
    int k;
    cin >> k;
    vector<int> c(26);
    for (int i = 0; i < 26; ++i) {
        cin >> c[i];
    }

    vector<mint> perm(k + 1, 0);
    perm[0] = 1;
    for (int i = 1; i <= k; ++i) {
        perm[i] = perm[i-1] * i;
    }

    // dp[i][j]: a_i以下の文字数を決めてその合計の長さがjになるような文字列の選び方
    vector<vector<mint>> dp(27, vector<mint>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= 26; ++i) {
        for (int ci = 0; ci <= c[i-1]; ++ci) {
            for (int j = ci; j <= k; ++j) {
                int pj = j - ci;
                // 長さpjの文字列の任意の箇所に同じci文字を挿入する場合の数は (pj+ci)_C_ci 通り
                dp[i][j] += dp[i-1][pj] * perm[pj+ci] / (perm[pj] * perm[ci]);
            }
        }
    }

    cout << accumulate(dp[26].begin() + 1, dp[26].end(), (mint)0).val() << endl;

    return 0;
}