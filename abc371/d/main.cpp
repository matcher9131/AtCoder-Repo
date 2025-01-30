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

using S = ll;
ll op(S a, S b) { return a + b; }
ll e() { return 0; }

int main() {
    vector<ll> t;
    int n;
    cin >> n;
    vector<ll> x(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
        t.push_back(x[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    int nq;
    cin >> nq;
    vector<ll> l(nq), r(nq);
    for (int i = 0; i < nq; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
        t.push_back(l[i]);
        t.push_back(r[i]);
    }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 0; i < n; ++i) {
        x[i] = lower_bound(t.begin(), t.end(), x[i]) - t.begin();
    }
    for (int i = 0; i < nq; ++i) {
        l[i] = lower_bound(t.begin(), t.end(), l[i]) - t.begin();
        r[i] = lower_bound(t.begin(), t.end(), r[i]) - t.begin();
    }

    atcoder::segtree<S, op, e> seg(t.size() + 1);
    for (int i = 0; i < n; ++i) {
        seg.set(x[i], p[i]);
    }

    for (int i = 0; i < nq; ++i) {
        cout << seg.prod(l[i], r[i] + 1) << endl;
    }

    return 0;
}