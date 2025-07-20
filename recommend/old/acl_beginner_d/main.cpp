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
    return max(a, b);
}
S e() {
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    atcoder::segtree<S, op, e> seg(3e5 + 1);
    for (int i = 0; i < n; ++i) {
        int l = max(0, a[i] - k);
        int r = min((int)3e5, a[i] + k) + 1;
        seg.set(a[i], seg.prod(l, r) + 1);
    }

    cout << seg.all_prod() << endl;

    return 0;
}