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
    ll sum;
    ll count;
};

S op(S a, S b) {
    return { a.sum + b.sum, a.count + b.count };
}
S e() {
    return { 0, 0 };
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size();

    unordered_map<ll, int> ctoi;
    for (int i = 0; i < n; ++i) {
        ctoi[a[i]] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    atcoder::segtree<S, op, e> seg(m);
    ll ans = 0;
    for (const ll ai : a) {
        int i = ctoi[ai];
        auto [sumLeft, countLeft] = seg.prod(0, i);
        ans += ai * countLeft - sumLeft;
        auto [sum, count] = seg.get(i);
        seg.set(i, { sum + ai, count + 1});
    }

    cout << ans << endl;

    return 0;
}