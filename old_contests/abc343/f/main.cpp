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
#include <atcoder/segtree>
using namespace std;
using ll = long long;

struct S {
    int first;
    int firstCount;
    int second;
    int secondCount;
};
S op(S a, S b) {
    map<int, int> m;
    m[a.first] += a.firstCount;
    m[a.second] += a.secondCount;
    m[b.first] += b.firstCount;
    m[b.second] += b.secondCount;
    auto it1 = m.end();
    --it1;
    auto it2 = m.end();
    --it2;
    --it2;
    return {
        it1->first,
        it1->second,
        it2->first,
        it2->second
    };
}
S e() {
    return { -1, 0, -2, 0 };
}

int main() {
    int n, nq;
    cin >> n >> nq;
    atcoder::segtree<S, op, e> seg(n);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        seg.set(i, { ai, 1, -1, 0 });
    }

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            seg.set(p, { x, 1, -1, 0 });
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            S p = seg.prod(l, r);
            cout << (p.second == -1 ? 0 : p.secondCount) << endl;
        }
    }

    return 0;
}