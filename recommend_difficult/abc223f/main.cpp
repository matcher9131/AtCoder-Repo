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

using S = int;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return 1e8;
}
using F = int;
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
    int n, nq;
    string s;
    cin >> n >> nq >> s;

    vector<int> lv(n+1);
    for (int i = 0; i < n; ++i) {
        lv[i+1] = lv[i] + (s[i] == '(' ? 1 : -1);
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(lv);

    while (nq--) {
        int k, l, r;
        cin >> k >> l >> r;
        if (k == 1) {
            if (s[l-1] == s[r-1]) continue;
            seg.apply(l, r, s[l-1] == '(' ? -2 : 2);
            swap(s[l-1], s[r-1]);
        } else {
            int baseLv = seg.get(l-1);
            bool ans = seg.get(r) == baseLv && seg.prod(l, r) >= baseLv;
            cout << (ans ? "Yes" : "No") << endl;
        }
    }

    return 0;
}