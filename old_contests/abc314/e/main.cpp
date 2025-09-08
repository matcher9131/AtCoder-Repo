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
using namespace std;
using ll = long long;

constexpr double INF = 1e8;

int main() {
    int n, m;
    cin >> n >> m;
    vector<double> c(n);
    vector<vector<int>> s(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        int p;
        cin >> p;
        for (int j = 0; j < p; ++j) {
            int sij;
            cin >> sij;
            if (sij > 0) s[i].push_back(sij);
        }
        c[i] *= (double)p / s[i].size();
    }

    // dp[x] = 現在のポイントがxのとき、合計がMポイントになるまでに支払う金額の期待値の最小値
    vector<double> dp(m + 101);
    fill(dp.begin(), dp.begin() + m, INF);
    for (int x = m - 1; x >= 0; --x) {
        for (int i = 0; i < n; ++i) {
            double e = 0;
            for (int j = 0; j < s[i].size(); ++j) {
                e += dp[x + s[i][j]];
            }
            e /= s[i].size();
            e += c[i];
            dp[x] = min(dp[x], e);
        }
    }

    cout << setprecision(15) << dp[0] << endl;

    return 0;
}