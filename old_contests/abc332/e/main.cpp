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
    int n, d;
    cin >> n >> d;
    vector<double> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    sort(w.begin(), w.end(), greater<double>());
    double avg = accumulate(w.begin(), w.end(), 0.0) / d;

    // dp[S][j]: グッズの集合がSでそれらをj袋に分けたときにおける分散の2乗の最小値
    // （ただしここで言う分散は平均値として全D袋の平均値を用いる）
    vector<vector<double>> dp(1 << n, vector<double>(d+1, 1e30));

    // dp[S][1]
    for (int bit = 0; bit < 1 << n; ++bit) {
        double ws = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) ws += w[i];
        }
        dp[bit][1] = (ws - avg) * (ws - avg);
    }

    for (int j = 2; j <= d; ++j) {
        for (int bit = 0; bit < 1 << n; ++bit) {
            int subBit = bit;
            while (true) {
                dp[bit][j] = min(dp[bit][j], dp[bit ^ subBit][j-1] + dp[subBit][1]);
                if (subBit == 0) break;
                subBit = (subBit - 1) & bit;
            }
        }
    }

    double ans = dp[(1 << n) - 1][d] / d;
    cout << setprecision(15) << ans << endl;

    return 0;
}