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
    int _h, _w, k, x1, y1, x2, y2;
    cin >> _h >> _w >> k >> x1 >> y1 >> x2 >> y2;
    mint h = _h, w = _w;

    // dpx[i][bx][by]: i回の操作の後にルークのいる場所(x,y)がbx = x == x2かつby = y == y2を満たすような場合の数
    vector<vector<vector<mint>>> dp(k+1, vector<vector<mint>>(2, vector<mint>(2)));
    for (int bx = 0; bx < 2; ++bx) {
        for (int by = 0; by < 2; ++by) {
            dp[0][bx][by] = ((x1 == x2) == bx) && ((y1 == y2) == by);
        }
    }
    for (int i = 1; i <= k; ++i) {
        dp[i][0][0] = (h - 2 + w - 2) * dp[i-1][0][0] + (h - 1) * dp[i-1][1][0] + (w - 1) * dp[i-1][0][1];
        dp[i][1][0] = dp[i-1][0][0] + (w - 2) * dp[i-1][1][0] + (w - 1) * dp[i-1][1][1];
        dp[i][0][1] = dp[i-1][0][0] + (h - 2) * dp[i-1][0][1] + (h - 1) * dp[i-1][1][1];
        dp[i][1][1] = dp[i-1][1][0] + dp[i-1][0][1];
    }

    cout << dp[k][1][1].val() << endl;
    return 0;
}