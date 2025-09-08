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

int main() {
    int n, nq;
    cin >> n >> nq;
    vector<char> h(nq + 1);
    vector<int> t(nq + 1);
    h[0] = 'L';
    t[0] = 0;
    for (int i = 1; i < nq + 1; ++i) {
        cin >> h[i] >> t[i];
        --t[i];
    }

    auto pmod = [&](int x) {
        int r = x % n;
        return r >= 0 ? r : r + n;
    };

    // dp[i][j]: i番目(1-indexed)のクエリが終了時にサブハンドがjの位置にあるような状態にするのに必要な最小の累計操作回数
    vector<unordered_map<int, int>> dp(nq + 1, unordered_map<int, int>());
    auto insertOrSetMin = [&](int i, int j, int newValue) {
        if (dp[i].contains(j)) {
            dp[i][j] = min(dp[i][j], newValue);
        } else {
            dp[i][j] = newValue;
        }
    };
    dp[0][1] = 0;
    for (int i = 1; i < nq + 1; ++i) {
        for (const auto& [j, c] : dp[i - 1]) {
            int main = h[i] == h[i - 1] ? t[i - 1] : j;
            int sub = h[i] == h[i - 1] ? j : t[i - 1];
            int goal = t[i];
            // 右方向
            if (pmod(goal - main) < pmod(sub - main)) {
                // サブハンドが邪魔にならない
                insertOrSetMin(i, sub, c + pmod(goal - main));
            } else {
                // サブハンドが邪魔になるので右へ移動
                insertOrSetMin(i, pmod(goal + 1), c + pmod(goal - main) + pmod(goal + 1 - sub));
            }
            // 左方向
            if (pmod(main - goal) < pmod(main - sub)) {
                // サブハンドが邪魔にならない
                insertOrSetMin(i, sub, c + pmod(main - goal));
            } else {
                // サブハンドが邪魔になるので左へ移動
                insertOrSetMin(i, pmod(goal - 1), c + pmod(main - goal) + pmod(sub - goal + 1));
            }
        }
    }

    int ans = 1e9;
    for (const auto& [_, c] : dp[nq]) {
        ans = min(ans, c);
    }

    cout << ans << endl;

    return 0;
}