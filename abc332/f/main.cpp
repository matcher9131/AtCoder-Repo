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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

using S = mint;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}
struct F {
    mint mul;
    mint add;
};
S mapping(F f, S x) {
    return x * f.mul + f.add;
}
F composition(F f, F g) {
    return { f.mul * g.mul, f.mul * g.add + f.add };
}
F id() {
    return { 1, 0 };
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<mint> a(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        --r;
        mint d = r - l + 1;
        mint p = d.inv();
        seg.apply(l, r+1, { 1 - p, x * p });
    }

    for (int i = 0; i < n; ++i) {
        cout << seg.get(i).val() << " \n"[i == n - 1];
    }

    return 0;
}