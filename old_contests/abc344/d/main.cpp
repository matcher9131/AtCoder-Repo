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

constexpr int INF = 1e8;

int main() {
    string t;
    int n;
    cin >> t >> n;
    int m = t.size();
    vector<vector<string>> s(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        for (int j = 0; j < ai; ++j) {
            string sij;
            cin >> sij;
            s[i].push_back(sij);
        }
    }

    // dp[i][k]: i(1-index)番目まで見てTの先頭k文字が一致するのに必要な金額の最小値
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= m; ++k) {
            dp[i+1][k] = min(dp[i+1][k], dp[i][k]);
            for (const string &sij : s[i]) {
                int pos = t.find(sij, k);
                if (pos == k) {
                    dp[i+1][k+(int)sij.size()] = min(dp[i+1][k+(int)sij.size()], dp[i][k] + 1);
                }
            }
        }
    }

    cout << (dp[n][m] >= INF ? -1 : dp[n][m]) << endl;

    return 0;
}