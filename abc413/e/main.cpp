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

void solve() {
    int n;
    cin >> n;
    vector<ll> p(1 << n);
    for (int i = 0; i < 1 << n; ++i) {
        cin >> p[i];
    }

    atcoder::segtree<S, op, e> seg(p);

    for (int i = n; i > 0; --i) {
        for (int j = 0; j < 1 << (n-i); ++j) {
            int l = j * (1 << i);
            int r = (j+1) * (1<<i);
            if (seg.prod(l, (l+r) / 2) > seg.prod((l+r) / 2, r)) {
                for (int k = 0; k < (r-l) / 2; ++k) {
                    ll tmp = seg.get(l+k);
                    seg.set(l+k, seg.get(r-1-k));
                    seg.set(r-1-k, tmp);
                }
            }
        }
    }

    for (int i = 0; i < (int)p.size(); ++i) {
        cout << seg.get(i) << " \n"[i == (int)p.size() - 1];
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}