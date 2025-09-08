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
    int val;
    int l_len;
    char l_ch;
    int r_len;
    char r_ch;
};
S op(S a, S b) {
    if (a.l_ch == 0) return b;
    if (b.l_ch == 0) return a;
    if (a.r_len == 0) {
        if (b.r_len == 0) {
            if (a.l_ch == b.l_ch) {
                // AA|AA
                return { a.val + b.val, a.l_len + b.l_len, a.l_ch, 0, 0 };
            } else {
                // AA|BB
                return { max(a.val, b.val), a.l_len, a.l_ch, b.l_len, b.l_ch };
            }
        } else {
            if (a.l_ch == b.l_ch) {
                // AA|AB
                return { max(a.val + b.l_len, b.val), a.l_len + b.l_len, a.l_ch, b.r_len, b.r_ch };
            } else {
                // AA|BC
                return { max(a.val, b.val), a.l_len, a.l_ch, b.r_len, b.r_ch };
            }
        }
    } else {
        if (b.r_len == 0) {
            if (a.r_ch == b.l_ch) {
                // AB|BB
                return { max(a.val, a.r_len + b.val), a.l_len, a.l_ch, a.r_len + b.l_len, b.l_ch };
            } else {
                // AB|CC
                return { max(a.val, b.val), a.l_len, a.l_ch, b.l_len, b.l_ch };
            }
        } else {
            if (a.r_ch == b.l_ch) {
                // AB|BC
                return { max({ a.val, a.r_len + b.l_len, b.val }), a.l_len, a.l_ch, b.r_len, b.r_ch };
            } else {
                // AB|CD
                return { max(a.val, b.val), a.l_len, a.l_ch, b.r_len, b.r_ch };
            }
        }
    }
}
S e() {
    return { 0, 0, 0, 0, 0 };
}

int main() {
    ll n, nq;
    string s;
    cin >> n >> nq >> s;
    atcoder::segtree<S, op, e> seg(n);
    for (int i = 0; i < n; ++i) {
        seg.set(i, { 1, 1, s[i], 0, 0 });
    }

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i;
            char x;
            cin >> i >> x;
            --i;
            seg.set(i, { 1, 1, x, 0, 0 });
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            cout << seg.prod(l, r+1).val << endl;
        }
    }

    return 0;
}