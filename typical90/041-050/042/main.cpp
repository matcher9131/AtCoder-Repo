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
    int k;
    cin >> k;

    if (k % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<mint> dp(k + 10);
    dp[0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= 9; ++j) {
            dp[i + j] += dp[i];
        }
    }

    cout << dp[k].val() << endl;

    return 0;
}