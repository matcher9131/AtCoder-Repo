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

constexpr int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        d[a][b] = w;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] == INF || d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // dp[i][j]: 訪れた頂点集合がiで最後に訪れた頂点がjになるようなウォークの辺の重みの総和の最小値
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }

    for (int bit = 0; bit < 1 << n; ++bit) {
        for (int from = 0; from < n; ++from) {
            if ((bit & (1 << from)) == 0) continue;
            if (dp[bit][from] == INF) continue;
            for (int to = 0; to < n; ++to) {
                if (bit & (1 << to)) continue;
                if (d[from][to] == INF) continue;
                int newBit = bit | (1 << to);
                dp[newBit][to] = min(dp[newBit][to], dp[bit][from] + d[from][to]);
            }
        }
    }

    ll ans = *min_element(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end());
    if (ans == INF) {
        cout << "No" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}