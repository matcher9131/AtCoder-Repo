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

constexpr ll INF = 1e18;
using S = ll;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}


int main() {
    ll n, nq;
    cin >> n >> nq;
    atcoder::segtree<S, op, e> seg(n);
    for (ll i = 0; i < n; ++i) {
        seg.set(i, 0);
    }
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < n) {
            seg.set(a[i], seg.get(a[i]) + 1);
        }
    }

    auto f = [](ll val){ return val > 0; };
    while (nq--) {
        ll i, x;
        cin >> i >> x;
        --i;
        if (a[i] < n) {
            seg.set(a[i], seg.get(a[i]) - 1);
        }
        a[i] = x;
        if (x < n) {
            seg.set(x, seg.get(x) + 1);
        }
        cout << seg.max_right(0, f) << endl;
    }

    return 0;
}