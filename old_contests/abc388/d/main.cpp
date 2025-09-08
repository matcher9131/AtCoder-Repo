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

ll op(ll a, ll b) {
    return min(a, b);
}
ll e() {
    return 1e18;
}
ll mapping(ll f, ll x) { return f + x; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

void display(const vector<int>& v) {
    if (!v.empty()) cout << v[0];
    for (int i = 1; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += i - (n - 1 - i);
    }

    atcoder::lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(a);

    for (int i = 0; i < n; ++i) {
        ll ai = seg.get(i);
        if (ai < 0) {
            seg.apply(n + ai, n, -1);
            seg.set(i, 0);
        }
    }
    
    cout << seg.get(0);
    for (int i = 1; i < n; ++i) {
        cout << " " << seg.get(i);
    }
    cout << endl;

    return 0;
}