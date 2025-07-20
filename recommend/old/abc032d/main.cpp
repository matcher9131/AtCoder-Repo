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
    int n;
    ll wMax;
    cin >> n >> wMax;
    ll vMax = 0;
    vector<ll> v(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> w[i];
        vMax = max(vMax, v[i]);
    }

    if (n <= 30) {
        ll ans = 0;
        vector<ll> v1sum(1 << (n + 1) / 2), v2sum(1 << n / 2), w1sum(1 << (n + 1) / 2), w2sum(1 << n / 2);
        for (int bit = 0; bit < v1sum.size(); ++bit) {
            for (int i = 0; i < (n + 1) / 2; ++i) {
                if (bit & (1 << i)) {
                    v1sum[bit] += v[i];
                    w1sum[bit] += w[i];
                }
            }
        }
        for (int bit = 0; bit < v2sum.size(); ++bit) {
            for (int i = 0; i < n / 2; ++i) {
                if (bit & (1 << i)) {
                    v2sum[bit] += v[i + (n + 1) / 2];
                    w2sum[bit] += w[i + (n + 1) / 2];
                }
            }
        }
        for (int i = 0; i < v1sum.size(); ++i) {
            if (w1sum[i] > wMax) continue;
            for (int j = 0; j < v2sum.size(); ++j) {
                if (w1sum[i] + w2sum[j] > wMax) continue;
                ans = max(ans, v1sum[i] + v2sum[j]);
            }
        }
        cout << ans << endl;
    } else if (vMax <= 1000) {
        int m = n * vMax;
        vector<vector<ll>> dp(n, vector<ll>(m + 1, 1e18));
        dp[0][0] = 0;
        dp[0][v[0]] = w[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = 0;
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                if (j >= v[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
        for (int j = m; j >= 0; --j) {
            if (dp[n - 1][j] <= wMax) {
                cout << j << endl;
                break;
            }
        }
    } else {
        vector<vector<ll>> dp(n, vector<ll>(wMax + 1));
        dp[0][w[0]] = v[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= wMax; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j >= w[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
    }

    return 0;
}