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
S op(S a, S b) { return a + b; }
S e() { return 0; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        a[i] = {ai, bi};
    }
    int nq;
    cin >> nq;
    // ci, di, qi
    vector<tuple<int, int, int>> q(nq);
    for (int qi = 0; qi < nq; ++qi) {
        int ci, di;
        cin >> ci >> di;
        --ci;
        --di;
        q[qi] = { ci, di, qi };
    }

    // qi, val
    vector<int> ans(nq);
    
    sort(a.begin(), a.end());
    sort(q.begin(), q.end());
    atcoder::segtree<S, op, e> segl(2*n);
    int aIndex = 0;
    for (const auto &[ci, di, qi] : q) {
        for (; aIndex < m && a[aIndex].first < ci; ++aIndex) {
            auto [ai, bi] = a[aIndex];
            segl.set(bi, segl.get(bi) + 1);
        }
        ans[qi] = segl.prod(ci, di);
    }

    sort(a.begin(), a.end(), [](auto &x, auto &y) { return x.second < y.second; });
    sort(q.begin(), q.end(), [](auto &x, auto &y) {
        auto [xci, xdi, _x] = x;
        auto [yci, ydi, _y] = y;
        return xdi == ydi ? xci < yci : xdi < ydi;
    });
    atcoder::segtree<S, op, e> segr(2*n);
    for (const auto &[ai, bi] : a) {
        segr.set(ai, segr.get(ai) + 1);
    }
    aIndex = 0;
    for (const auto &[ci, di, qi] : q) {
        for (; aIndex < m && a[aIndex].second < di; ++aIndex) {
            auto [ai, bi] = a[aIndex];
            segr.set(ai, segr.get(ai) - 1);
        }
        ans[qi] += segr.prod(ci, di);
    }

    for (int qi = 0; qi < nq; ++qi) {
        cout << ans[qi] << endl;
    }

    return 0;
}