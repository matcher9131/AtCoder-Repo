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
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using namespace atcoder;

ll op(ll x, ll y) { return max(x, y); }
ll e() { return 0; };
ll mapping(ll f, ll x) { return max(f, x); }
ll composition(ll f, ll g) { return max(f, g); }
ll id() { return 0; }

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> l(n), r(n);
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i] >> v[i];
    }

    vector<lazy_segtree<ll, op, e, ll, mapping, composition, id>> dp(n, lazy_segtree<ll, op, e, ll, mapping, composition, id>(w + 1));
    dp[0].apply(l[0], r[0] + 1, v[0]);
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        dp[i].apply(l[i], r[i] + 1, v[i]);
        for (int j = 1; j < w; ++j) {
            ll pv = dp[i - 1].get(j);
            if (pv == 0) continue;
            if (j + l[i] <= w) dp[i].apply(j + l[i], min(j + r[i] + 1, w + 1), pv + v[i]);
        }
    }

    ll ans = dp[n - 1].get(w);
    cout << (ans == 0 ? -1 : ans) << endl;

    return 0;
}