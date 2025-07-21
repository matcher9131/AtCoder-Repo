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

constexpr ll INF = 1e16;

using S = ll;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}
using F = ll;
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
    ll h, w, c;
    cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(h*w);
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> a[i][j];
            seg.set(i*w+j, a[i][j] + c * (i + j));
        }
    }

    ll ans = INF;
    for (ll j = 0; j < w; ++j) {
        for (ll i = 0; i < h; ++i) {
            ans = min(ans, a[i][j] + seg.prod(i*w+j+1, h*w));
            seg.apply(0, (i+1)*w, c);
            seg.apply((i+1)*w, h*w, -c);
        }
        // jインクリメントに備える
        for (ll i = 0; i < h; ++i) {
            seg.apply(i*w, (i+1)*w, c * (2*i - h));
            seg.apply(i*w, i*w+j+1, c);
            seg.apply(i*w+j+1, (i+1)*w, -c);
        }
    }
    
    cout << ans << endl;
    return 0;
}