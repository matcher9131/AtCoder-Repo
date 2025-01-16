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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    // next[x][i]:= j>iに対しA_j = xとなる最小のj（存在しないときはINF, jは1-indexed）
    vector<vector<int>> next(20, vector<int>(n + 1));
    for (int x = 0; x < 20; ++x) {
        next[x][n] = INF;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int x = 0; x < 20; ++x) {
            next[x][i] = next[x][i + 1];
        }
        next[a[i]][i] = i + 1;
    }

    int ans = 0;
    // dp[S] = i
    // 数列Anの先頭i'項で1122数列を作り、そのときに項に含まれる数の集合がちょうどSになるようなi'の最小値i
    vector<int> dp(1 << 20, INF);
    dp[0] = 0;
    for (int bit = 0; bit < (1<<20); ++bit) {
        int count = 0;
        for (int x = 0; x < 20; ++x) {
            if (bit & (1 << x)) {
                count += 2;
                int bitWithoutX = bit ^ (1 << x);
                if (dp[bitWithoutX] < INF && next[x][dp[bitWithoutX]] < INF) {
                    dp[bit] = min(dp[bit], next[x][next[x][dp[bitWithoutX]]]);
                }
            }
        }
        if (dp[bit] < INF) {
            ans = max(ans, count);
        }
    }

    cout << ans << endl;

    return 0;
}