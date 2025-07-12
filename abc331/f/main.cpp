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
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

constexpr int BASE = 27;

struct S {
    mint hash;
    int len;
};
S op(S a, S b) {
    return {
        a.hash * ((mint)BASE).pow(b.len) + b.hash,
        a.len + b.len
    };
}
S e() {
    return { 0, 0 };
}

int main() {
    int n, nq;
    string s;
    cin >> n >> nq >> s;
    atcoder::segtree<S, op, e> seg(n), rSeg(n);
    for (int i = 0; i < n; ++i) {
        seg.set(i, { s[i], 1 });
        rSeg.set(n-1-i, { s[i], 1 });
    }

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            char c;
            cin >> x >> c;
            --x;
            seg.set(x, { c, 1 });
            rSeg.set(n-1-x, { c, 1 });
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            mint hash1 = seg.prod(l, r+1).hash;
            mint hash2 = rSeg.prod(n-1-r, n-l).hash;
            cout << (hash1 == hash2 ? "Yes" : "No") << endl;
        }
    }

    return 0;
}