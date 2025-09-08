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

vector<vector<int>> part(int n, int max) {
    vector<vector<int>> result;
    if (n == 0) {
        result.emplace_back(vector<int>());
        return result;
    }
    for (int first = min(n, max); first >= 1; --first) {
        for (auto &v : part(n - first, first)) {
            v.insert(v.begin(), first);
            result.push_back(v);
        }
    }
    return result;
}

int main() {
    int n, t, m, k;
    cin >> n >> t >> m >> k;

    vector<vector<int>> partition = part(m, m);

    // memo[i][j]: 残りiセットでj点を取る最高確率
    vector<vector<double>> memo(t+1, vector<double>(k+1, -1.0));
    memo[0][0] = 1.0;
    for (int ki = 1; ki <= k; ++ki) {
        memo[0][ki] = 0;
    }
    function<double(int, int)> dfs = [&](int rt, int rk) {
        if (memo[rt][rk] != -1.0) return memo[rt][rk];

        double probMax = 0;
        for (const auto &v : partition) {
            double probCurrent = 0;
            if ((int)v.size() > min(n, m)) continue;
            for (const int ci : v) {
                probCurrent += dfs(rt - 1, max(0, rk - ci));
            }
            probCurrent += (n - v.size()) * dfs(rt - 1, rk);
            probMax = max(probMax, probCurrent);
        }
        return memo[rt][rk] = probMax / n;
    };

    cout << setprecision(15) << dfs(t, k) << endl;

    return 0;
}