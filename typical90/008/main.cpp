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

const string ACD = "atcoder";
const int m = ACD.size();

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<mint>> dp(n + 1, vector<mint>(m + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][j] += dp[i][j];
            if (j < m && s[i] == ACD[j]) dp[i + 1][j + 1] += dp[i][j];
        }
    }
    
    cout << dp[n][m].val() << endl;

    return 0;
}