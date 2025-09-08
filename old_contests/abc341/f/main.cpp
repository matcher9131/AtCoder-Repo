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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> wOrdered(n);
    for (int i = 0; i < n; ++i) {
        wOrdered[i] = { w[i], i };
    }
    sort(wOrdered.begin(), wOrdered.end());

    vector<ll> descendant(n);
    for (const auto &[wi, i] : wOrdered) {
        int numEdge = g[i].size();
        vector<vector<ll>> dp(numEdge+1, vector<ll>(wi));
        for (int wj = 0; wj < wi; ++wj) {
            dp[0][wj] = 1;
        }
        for (int ei = 0; ei < numEdge; ++ei) {
            int to = g[i][ei];
            for (int wj = 0; wj < wi; ++wj) {
                dp[ei+1][wj] = max(dp[ei+1][wj], dp[ei][wj]);
                if (wj + w[to] < wi) {
                    dp[ei+1][wj + w[to]] = max(dp[ei+1][wj + w[to]], dp[ei][wj] + descendant[to]);
                }
            }
        }
        descendant[i] = dp[numEdge][wi-1];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * descendant[i];
    }
    cout << ans << endl;

    return 0;
}