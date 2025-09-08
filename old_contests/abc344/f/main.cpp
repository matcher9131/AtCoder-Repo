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

ll ceil(ll x, ll y) {
    return (x + y - 1) / y;
}

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> p(n, vector<ll>(n)), r(n, vector<ll>(n)), d(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            cin >> r[i][j];
        }
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }

    // dp[i][j][k]: マス(i,j)に到達するまでにpの最大値がkとなるようなルートの[行動回数, 所持金]の最適値（行動回数昇順＆所持金降順）
    vector<vector<unordered_map<ll, pair<ll, ll>>>> dp(n, vector<unordered_map<ll, pair<ll, ll>>>(n));
    dp[0][0][p[0][0]] = { 0, 0 };

    auto update = [&](int i, int j, ll k, pair<ll, ll> newValue) {
        if (dp[i][j].contains(k)) {
            if (newValue.first < dp[i][j][k].first || (newValue.first == dp[i][j][k].first && newValue.second > dp[i][j][k].second)) {
                dp[i][j][k] = newValue;
            }
        } else {
            dp[i][j][k] = newValue;
        }
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (const auto &[pMax, val] : dp[i][j]) {
                auto [count, possession] = val;
                if (i < n-1) {
                    ll remain = possession >= d[i][j] ? 0 : ceil(d[i][j] - possession, pMax);
                    ll newPossession = possession + remain * pMax - d[i][j];
                    update(i+1, j, max(pMax, p[i+1][j]), {count + remain + 1, newPossession});
                }
                if (j < n-1) {
                    ll remain = possession >= r[i][j] ? 0 : ceil(r[i][j] - possession, pMax);
                    ll newPossession = possession + remain * pMax - r[i][j];
                    update(i, j+1, max(pMax, p[i][j+1]), {count + remain + 1, newPossession});
                }
            }
        }
    }

    ll ans = 1e16;
    for (const auto &[_, val] : dp[n-1][n-1]) {
        ans = min(ans, val.first);
    }

    cout << ans << endl;
    return 0;
}