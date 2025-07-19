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
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    vector<ll> p(h+w-1);
    for (ll i = 0; i < h+w-1; ++i) {
        cin >> p[i];
    }
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            a[i][j] -= p[i+j];
        }
    }

    // dp[i][j]: マス(i,j)からスタートしてマス(h-1,w-1)までたどり着く（途中および終了後に空腹で倒れない）ような初期所持金の最小値
    vector<vector<ll>> dp(h, vector<ll>(w));
    dp[h-1][w-1] = max(0LL, -a[h-1][w-1]);
    for (ll i = h - 2; i >= 0; --i) {
        dp[i][w-1] = max(0LL, dp[i+1][w-1] - a[i][w-1]);
    }
    for (ll j = w - 2; j >= 0; --j) {
        dp[h-1][j] = max(0LL, dp[h-1][j+1] - a[h-1][j]);
    }
    for (ll i = h - 2; i >= 0; --i) {
        for (ll j = w - 2; j >= 0; --j) {
            dp[i][j] = max(0LL, min(dp[i+1][j], dp[i][j+1]) - a[i][j]);
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}