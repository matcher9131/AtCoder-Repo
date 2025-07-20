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
    ll n;
    cin >> n;
    vector<ll> x(n), c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> c[i];
        --c[i];
    }

    vector<vector<ll>> revC(n);
    for (ll i = 0; i < n; ++i) {
        revC[c[i]].push_back(x[i]);
    }
    for (ll ci = 0; ci < n; ++ci) {
        sort(revC[ci].begin(), revC[ci].end());
    }

    // dp[i][j]: 色iのボールをすべて回収したときにj=0:最も左、j=1:最も右にいる場合における移動距離の最小値（＆座標）
    vector<vector<pair<ll, ll>>> dp(n+1, vector<pair<ll, ll>>(2));
    dp[0][0] = { 0, 0 };
    dp[0][1] = { 0, 0 };
    for (ll ci = 0; ci < n; ++ci) {
        if (revC[ci].empty()) {
            dp[ci+1][0] = dp[ci][0];
            dp[ci+1][1] = dp[ci][1];
        } else if ((int)revC[ci].size() == 1) {
            ll to = revC[ci][0];
            auto [d0, x0] = dp[ci][0];
            auto [d1, x1] = dp[ci][1];
            dp[ci+1][0] = { min(d0 + abs(to - x0), d1 + abs(to - x1)), to };
            dp[ci+1][1] = dp[ci+1][0];
        } else {
            ll toL = revC[ci][0];
            ll toR = revC[ci].back();
            auto [d0, x0] = dp[ci][0];
            auto [d1, x1] = dp[ci][1];
            dp[ci+1][0] = { min(d0 + abs(toR - x0), d1 + abs(toR - x1)) + abs(toL - toR), toL };
            dp[ci+1][1] = { min(d0 + abs(toL - x0), d1 + abs(toL - x1)) + abs(toR - toL), toR };
        }
    }

    auto [d0, x0] = dp[n][0];
    auto [d1, x1] = dp[n][1];
    cout << min(d0 + abs(x0), d1 + abs(x1)) << endl;

    return 0;
}