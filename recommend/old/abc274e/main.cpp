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
using ull = unsigned long long;

constexpr double INF = 1e30;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<double> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<double> p(m), q(m);
    for (ll i = 0; i < m; ++i) {
        cin >> p[i] >> q[i];
    }

    auto getCoord= [&](int i) -> pair<double, double> {
        if (i == 0) return { 0, 0 };
        else if (i <= n) return { x[i-1], y[i-1] };
        else return { p[i-1-n], q[i-1-n] };
    };
    auto getTime = [&](int i, int j, ll speed) -> double {
        auto [x1, y1] = getCoord(i);
        auto [x2, y2] = getCoord(j);
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) / speed;
    };

    // dp[i][j]: すでに訪れた街・宝箱の集合がi、最後に訪れた箇所がjの状態になるまでの時間の最小値
    // j=0: 原点、1<=j<=n: 街、n<j<=n+m: 宝箱
    vector<vector<double>> dp(1 << (n + m), vector<double>(n+m+1, INF));
    dp[0][0] = 0;
    for (ull bit = 0; bit < 1ULL << (n + m); ++bit) {
        for (ll last = 0; last <= n+m; ++last) {
            if (dp[bit][last] == INF) continue;
            for (ll to = 1; to <= n+m; ++to) {
                if (bit & (1LL << (to-1))) continue;
                ull newBit = bit | (1ULL << (to-1));
                ll speed = 1LL << popcount(bit >> n);
                dp[newBit][to] = min(dp[newBit][to], dp[bit][last] + getTime(last, to, speed));
            }
        }
    }

    double ans = INF;
    for (ull boxBit = 0; boxBit < (1ULL << m); ++boxBit) {
        ull bit = (boxBit << n) | ((1ULL << n) - 1);
        for (ll last = 1; last <= n+m; ++last) {
            ll speed = 1LL << popcount(boxBit);
            double time = dp[bit][last] + getTime(0, last, speed);
            ans = min(ans, time);
        }
    }

    cout << setprecision(15) << ans << endl;

    return 0;
}