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

constexpr ll INF = 1e18;

using S = ll;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}
using F = ll;
S mapping(F f, S x) {
    return f + x;
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}

int main() {
    int n;
    ll d, a;
    cin >> n >> d >> a;
    vector<pair<ll, ll>> mob(n);
    for (int i = 0; i < n; ++i) {
        ll xi, hi;
        cin >> xi >> hi;
        mob[i] = { xi, hi };
    }
    sort(mob.begin(), mob.end());

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    for (int i = 0; i < n; ++i) {
        seg.set(i, mob[i].second);
    }

    ll ans = 0;
    for (int l = 0; l < n; ++l) {
        if (seg.get(l) <= 0) continue;
        int r = upper_bound(mob.begin(), mob.end(), make_pair(mob[l].first + 2 * d, INF)) - mob.begin();
        ll count = (seg.get(l) + a - 1) / a;
        ans += count;
        seg.apply(l, r, -a * count);
    }

    cout << ans << endl;
    return 0;
}