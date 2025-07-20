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
#include <atcoder/modint>
using namespace std;
using ull = unsigned long long;
using mint = atcoder::modint998244353;

int count_bit(ull x) {
    ull count = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);
    count = (count & 0x3333333333333333) + ((count >> 2) & 0x3333333333333333);
    count = (count & 0x0f0f0f0f0f0f0f0f) + ((count >> 4) & 0x0f0f0f0f0f0f0f0f);
    count = (count & 0x00ff00ff00ff00ff) + ((count >> 8) & 0x00ff00ff00ff00ff);
    count = (count & 0x0000ffff0000ffff) + ((count >> 16) & 0x0000ffff0000ffff);
    return (int)((count & 0x00000000ffffffff) + ((count >> 32) & 0x00000000ffffffff));
}

int msb(ull x) {
    if (x == 0) return -1;
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);
    return count_bit(x) - 1;
}

int main() {
    ull n, m;
    cin >> n >> m;

    int mm = msb(m) + 1;
    if (n > mm) {
        cout << 0 << endl;
        return 0;
    }

    // dp[i][j]: msb(a_i) = jとなるようなa_1, a_2, ... a_iの選び方の場合の数
    vector<vector<mint>> dp(n, vector<mint>(mm));
    for (int j = 0; j < mm; ++j) {
        if (j == mm - 1) dp[0][j] = m - (1ULL << j) + 1ULL;
        else dp[0][j] = 1ULL << j;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < mm; ++j) {
            for (int k = 0; k < j; ++k) {
                if (j == mm - 1) dp[i][j] += dp[i - 1][k] * (m - (1ULL << j) + 1ULL);
                else dp[i][j] += dp[i - 1][k] * (1ULL << j);
            }
        }
    }

    mint ans;
    for (int j = 0; j < mm; ++j) {
        ans += dp[n - 1][j];
    }

    cout << ans.val() << endl;

    return 0;
}