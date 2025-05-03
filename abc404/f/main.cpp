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
    int n, t, m, k;
    cin >> n >> t >> m >> k;

    // memo[i][j]: 残りiセットでj点を取る最高確率
    vector<vector<double>> memo(t+1, vector<double>(k+1, -1.0));
    for (int ki = 0; ki <= k; ++ki) {
        memo[0][ki] = (ki == 0 ? 1.0 : 0);
    }
    function<double(int, int)> dfs = [&](int rt, int rk) {
        if (memo[rt][rk] != -1.0) return memo[rt][rk];
        double prob = 0;
        for (int mi = 1; mi <= m; ++mi) {
            int nk = rk - mi;
            if (nk < 0) continue;
            prob = max(prob, (m / mi) / (double)n * dfs(rt - 1, nk) + dfs(rt - 1, rk));
        }
        return memo[rt][rk] = prob;
    };

    cout << setprecision(15) << dfs(t, k) << endl;

    //
    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j <= k; ++j) {
            cout << memo[i][j] << " \n"[j == k];
        }
    }
    //
    return 0;
}