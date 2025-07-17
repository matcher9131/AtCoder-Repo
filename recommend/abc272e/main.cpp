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

using S = int;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return (int)1e8;
}

int main() {
    int n, m;
    cin >> n >> m;
    atcoder::segtree<S, op, e> seg(n);
    for (ll i = 0; i < n; ++i) {
        seg.set(i, 0);
    }
    vector<ll> a(n);
    vector<vector<pair<ll, ll>>> pushToBe(m+1);
    queue<tuple<ll, ll, ll>> que;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (0 <= a[i] && a[i] < n) {
            que.emplace(a[i], i+1, 0);
            seg.set(a[i], seg.get(a[i]) + 1);
        } else if (a[i] < 0) {
            ll k = (abs(a[i]) + i) / (i+1);
            if (k <= m) {
                pushToBe[k].emplace_back(a[i] + k * (i+1), i+1);
            }
        }
    }

    auto f = [](int val) { return val > 0; };
    for (ll i = 1; i <= m; ++i) {
        while (!que.empty()) {
            auto [val, diff, index] = que.front();
            if (index != i-1) break;
            que.pop();
            seg.set(val, seg.get(val) - 1);
            ll newVal = val + diff;
            if (newVal < n) {
                que.emplace(newVal, diff, i);
                seg.set(newVal, seg.get(newVal) + 1);
            }
        }
        for (const auto &[initial, diff] : pushToBe[i]) {
            que.emplace(initial, diff, i);
            seg.set(initial, seg.get(initial) + 1);
        }
        cout << seg.max_right(0, f) << endl;
    }

    return 0;
}