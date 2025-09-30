#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

struct S {
    char c;
    ll i;
};
S op(S a, S b) {
    if (a.c == b.c) return {a.c, max(a.i, b.i)};
    else if (a.c < b.c) return a;
    else return b;
}
S e() {
    return {(char)127, -1};
}

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    atcoder::segtree<S, op, e> seg(n);
    for (ll i = 0; i < n; ++i) {
        seg.set(i, {s[i], i});
    }

    ll left = 0, right = n;
    while (left < right) {
        S target = seg.prod(left+1, right);
        if (seg.get(left).c <= target.c) {
            ++left;
        } else {
            S sl = seg.get(left);
            seg.set(left, {target.c, left});
            seg.set(target.i, {sl.c, target.i});
            ++left;
            right = target.i;
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << seg.get(i).c;
    }
    cout << endl;
    return 0;
}