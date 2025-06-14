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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m = *max_element(a.begin(), a.end());

    // seg[j]: jを末項とする条件を満たす数列の長さの最大値
    atcoder::segtree<S, op, e> seg(m+1);
    for (int i = 0; i < n; ++i) {
        int l = max(0, a[i] - d);
        int r = min(m, a[i] + d);
        seg.set(a[i], seg.prod(l, r + 1) + 1);
    }

    cout << seg.all_prod() << endl;


    return 0;
}