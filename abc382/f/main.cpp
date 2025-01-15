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

constexpr int INF = 1e9;
using S = int;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}
using F = int;
S mapping(F f, S x) {
    return min(f, x);
}
F composition(F f, F g) {
    return min(f, g);
}
F id() {
    return INF;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    // row, index, [left, right)
    vector<tuple<int, int, int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        int r, c, l;
        cin >> r >> c >> l;
        --r;
        --c;
        b[i] = make_tuple(r, i, c, c + l);
    }

    sort(b.begin(), b.end(), greater<tuple<int, int, int, int>>());

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<int>(w, h));
    vector<int> ans(n);
    for (const auto& [_, i, l, r] : b) {
        int cMin = seg.prod(l, r);
        seg.apply(l, r, cMin - 1);
        ans[i] = cMin - 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}