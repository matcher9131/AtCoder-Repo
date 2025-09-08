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

using S = ll;
S op(S a, S b) {
    return max(a, b);
}
S e() {
    return 0;
}
using F = ll;
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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    for (int j = 0; j < m; ++j) {
        ll c = seg.get(b[j]);
        seg.set(b[j], 0);
        ll left = b[j] + 1;
        ll right = b[j] + c;
        ll q = right / n;
        ll r = right % n;
        seg.apply(0, (int)(r + 1), q+1);
        seg.apply((int)(r + 1), n, q);
        seg.apply(0, left, -1);
    }

    for (int i = 0; i < n; ++i) {
        cout << seg.get(i) << " \n"[i == n - 1];
    }

    return 0;
}