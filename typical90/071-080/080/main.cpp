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
    // bs[i] = a[j]の下からi桁目のビットが1であるようなjの集合をビットで表したもの
    vector<ll> bs(d);
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        for (int j = 0; j < d; ++j) {
            if (ai & (1LL << j)) {
                bs[j] |= (1LL << i);
            }
        }
    }

    // dp[i][j] = 下からi桁のビットでカバーできる集合がjになる場合の数
    vector<vector<ll>> dp(d + 1, vector<ll>(1LL << n));
    dp[0][0] = 1LL;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < 1<<n; ++j) {
            dp[i+1][j] += dp[i][j];
            dp[i+1][j | bs[i]] += dp[i][j];
        }
    }
    
    cout << dp[d][(1 << n) - 1] << endl;

    return 0;
}