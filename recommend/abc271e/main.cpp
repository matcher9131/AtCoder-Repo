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

constexpr ll INF = 1e16;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m), b(m), c(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i];
        --b[i];
    }
    vector<ll> e(k);
    for (ll ki = 0; ki < k; ++ki) {
        cin >> e[ki];
        --e[ki];
    }

    // dp[i]: 都市0から都市iへ行く方法で経路がE[0..j]の部分列になるようなものの長さの和の最小値(in-placeに更新)
    vector<ll> dp(n, INF);
    dp[0] = 0;
    for (ll ki = 0; ki < k; ++ki) {
        if (dp[a[e[ki]]] == INF) continue;
        dp[b[e[ki]]] = min(dp[b[e[ki]]], dp[a[e[ki]]] + c[e[ki]]);
    }
    
    cout << (dp[n-1] == INF ? -1 : dp[n-1]) << endl;
    return 0;
}