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
using F = int;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}
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
    cin >> n;
    vector<pair<int, int>> contests(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        contests[i] = make_pair(l, r);
    }
    int nq;
    cin >> nq;
    vector<pair<int, int>> q(nq);
    for (int i = 0; i < nq; ++i) {
        int qi;
        cin >> qi;
        q[i] = make_pair(qi, i);
    }
    sort(q.begin(), q.end());

    vector<int> x(nq);
    for (int i = 0; i < nq; ++i) {
        x[i] = q[i].first;
    }
    
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(x);

    auto isOKMin = [&](int i, int l) {
        return seg.get(i) >= l;
    };
    auto isOKMax = [&](int i, int r) {
        return seg.get(i) <= r;
    };
    auto searchLeft = [&](int l) {
        int ng = -1;
        int ok = nq;

        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (isOKMin(mid, l)) ok = mid;
            else ng = mid;
        }
        return ok;
    };
    auto searchRight = [&](int r) {
        int ng = nq;
        int ok = -1;

        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (isOKMax(mid, r)) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    for (const auto& [l, r] : contests) {
        int li = searchLeft(l);
        int ri = searchRight(r);
        seg.apply(li, ri + 1, 1);
    }

    vector<int> ans(nq);
    for (int i = 0; i < nq; ++i) {
        ans[q[i].second] = seg.get(i);
    }
    for (int i = 0; i < nq; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}