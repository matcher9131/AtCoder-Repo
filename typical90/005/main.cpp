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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;


int main() {
    ll n;
    int b, k;
    cin >> n >> b >> k;
    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }

    if (n == 1) {
        int ans = 0;
        for (const int d : c) if (d % b == 0) ++ans;
        cout << ans << endl;
        return 0;
    }

    int m = 0;
    while (n > (1LL << m)) ++m;

    // 10^(2^i)をbで割った余り
    vector<int> mod10(m);
    mod10[0] = 10 % b;
    for (int i = 1; i < m; ++i) {
        mod10[i] = mod10[i - 1] * mod10[i - 1] % b;
    }
    // dp[i][j]: c_1, c_2, ... , c_kのみを使ってできる2^i桁の整数でbで割った余りがjのものの個数
    vector<vector<mint>> dp(m, vector<mint>(b));
    for (const int d : c) {
        ++dp[0][d % b];
    }
    for (int i = 1; i < m; ++i) {
        for (int j1 = 0; j1 < b; ++j1) {
            for (int j2 = 0; j2 < b; ++j2) {
                int newJ = (j1 * mod10[i - 1] + j2) % b;
                dp[i][newJ] += dp[i - 1][j1] * dp[i - 1][j2];
            }
        }
    }
    
    vector<mint> modn(1, 1);
    int r = 1;
    for (int i = 0; i < m; ++i) {
        if (n & (1LL << i)) {
            vector<mint> t(b);
            for (int j1 = 0; j1 < modn.size(); ++j1) {
                for (int j2 = 0; j2 < b; ++j2) {
                    int newJ = j2 * r % b;
                    t[(j1 + newJ) % b] += modn[j1] * dp[i][j2];
                }
            }
            modn = t;
            r = r * mod10[i] % b;
        }
    }

    cout << modn[0].val() << endl;

    return 0;
}