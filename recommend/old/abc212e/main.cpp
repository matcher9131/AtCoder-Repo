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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> u(m), v(m);
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<mint>> dp(k+1, vector<mint>(n));
    vector<mint> dps(k+1);
    dp[0][0] = 1;
    dps[0] = 1;
    for (ll i = 1; i <= k; ++i) {
        for (ll j = 0; j < n; ++j) {
            dp[i][j] = dps[i-1];
            dp[i][j] -= dp[i-1][j];
            for (const ll to : g[j]) {
                dp[i][j] -= dp[i-1][to];
            }
            dps[i] += dp[i][j];
        }
    }

    cout << dp[k][0].val() << endl;
    return 0;
}