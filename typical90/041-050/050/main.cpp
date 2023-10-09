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
    int n, l;
    cin >> n >> l;

    vector<mint> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] += dp[i - 1];
        if (i >= l) dp[i] += dp[i - l];
    }

    cout << dp[n].val() << endl;

    return 0;
}