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

constexpr int INF = 1e8;

using S = int;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}
using F = int;
F mapping(F f, S x) {
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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n+2);
    seg.set(0, 1);
    seg.set(n+1, n);
    for (int i = 1; i <= n; ++i) {
        seg.set(i, a[i-1] + i-1);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, seg.all_prod());
        seg.apply(i+1, n+2, -1);
        seg.apply(0, i+1, 1);
    }

    cout << ans << endl;
    return 0;
}