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
using namespace std;
using ll = long long;


constexpr double INF = 1LL << 50;

void chMin(double& x, double y) {
    if (y < x) x = y;
}

double dist(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    int m = min(n, 20);

    // dp[i][j]: チェックポイントiまでj個をスルーしてきたときの移動距離の最小値
    vector<vector<double>> dp(n, vector<double>(m, INF));
    dp[0][0] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 20; ++k) {
                if (i - k - 1 >= 0 && j - k >= 0) {
                    chMin(dp[i][j], dp[i - k - 1][j - k] + dist(x[i], y[i], x[i - k - 1], y[i - k - 1]));
                }
            }
        }
    }

    double answer = INF;
    for (int j = 0; j < m; ++j) {
        chMin(answer, dp[n - 1][j] + (j == 0 ? 0 : 1 << (j - 1)));
    }

    cout << setprecision(15) << answer << endl;

    
    return 0;
}