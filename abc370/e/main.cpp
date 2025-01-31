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
using mint = atcoder::modint998244353;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), sum(n + 1);
    vector<mint> dp(n + 1), sdp(n + 1);
    dp[0] = 1;
    sdp[0] = 1;
    unordered_map<ll, mint> m;
    m[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
        dp[i + 1] = sdp[i] - m[sum[i + 1] - k];
        m[sum[i + 1]] += dp[i + 1];
        sdp[i + 1] = sdp[i] + dp[i + 1];
    }

    cout << dp[n].val() << endl;

    return 0;
}