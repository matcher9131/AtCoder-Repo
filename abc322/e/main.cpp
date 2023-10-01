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

constexpr ll INF = 1e18;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<ll> c(n);
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }

    auto getParam = [&](int i) {
        int r = 0;
        for (int j = 0; j < k; ++j) {
            r |= a[i][j] << (3 * j);
        }
        return r;
    };
    auto sumParams = [&](int p1, int p2) {
        int r = 0;
        for (int j = 0; j < k; ++j) {
            r |= min(p, ((p1 >> (3 * j)) & 7) + ((p2 >> (3 * j)) & 7)) << (3 * j);
        }
        return r;
    };
    auto changeMin = [](ll &x, ll y) {
        if (x > y) x = y;
    };

    int m = 1 << (3 * k);
    // dp[i][j]: i個目までの開発案まで見てパラメータの状態がjになるような最小のコストの和
    vector<vector<ll>> dp(n + 1, vector<ll>(m, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            changeMin(dp[i + 1][j], dp[i][j]);
            changeMin(dp[i + 1][sumParams(j, getParam(i))], dp[i][j] + c[i]);
        }
    }

    auto isOK = [&](int j) {
        for (int ki = 0; ki < k; ++ki) {
            if (((j >> (3 * ki)) & 7) < p) return false;
        }
        return true;
    };
    ll ans = INF;
    for (int j = 0; j < m; ++j) {
        if(isOK(j)) ans = min(ans, dp[n][j]);
    }
    cout << (ans >= INF ? -1 : ans) << endl;

    return 0;
}