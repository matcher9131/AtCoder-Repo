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

constexpr ll INF = 1e12;

int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<ll>> a(3, vector<ll>());
    vector<vector<int>> c(3, vector<int>());
    for (int i = 0; i < n; ++i) {
        int v, ci;
        ll ai;
        cin >> v >> ai >> ci;
        --v;
        a[v].push_back(ai);
        c[v].push_back(ci);
    }

    vector<vector<vector<ll>>> dp(3);
    for (int v = 0; v < 3; ++v) {
        int m = a[v].size();
        dp[v] = vector<vector<ll>>(m + 1, vector<ll>(x + 1));

        for (int i = 1; i <= m; ++i) {
            ll ai = a[v][i - 1];
            int ci = c[v][i - 1];
            for (int j = 0; j <= x; ++j) {
                if (j - ci >= 0) {
                    dp[v][i][j] = max(dp[v][i - 1][j], dp[v][i-1][j-ci] + ai);
                } else {
                    dp[v][i][j] = dp[v][i - 1][j];
                }
            }
        }
    }

    // ビタミンvをvalue取るのに必要なカロリーの最低値（不可能なときは-1）
    auto cMin = [&](int v, ll value) -> int {
        for (int j = 0; j <= dp[v].back().size(); ++j) {
            if (dp[v].back()[j] >= value) return j;
        }
        return -1;
    };
    
    ll ok = 0;
    ll ng = INF;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll c1 = cMin(0, mid);
        ll c2 = cMin(1, mid);
        ll c3 = cMin(2, mid);
        if (c1 >= 0 && c2 >= 0 && c3 >= 0 && c1 + c2 + c3 <= x) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}