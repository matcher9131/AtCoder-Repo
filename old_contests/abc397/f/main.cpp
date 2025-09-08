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

using S = int;
S op(S a, S b) {
    return max(a, b);
}
S e() {
    return -1e9;
}
using F = int;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // l[i] = [0, i]に含まれる種類数
    // r[i] = [i, n)に含まれる種類数
    vector<int> l(n), r(n);
    unordered_set<int> lSet, rSet;
    for (int i = 0; i < n; ++i) {
        lSet.insert(a[i]);
        l[i] = lSet.size();
        rSet.insert(a[n - 1 - i]);
        r[n - 1 - i] = rSet.size();
    }

    // [0, i]を2つの連続部分列に含まれる種類数の和の最大値
    vector<int> ansLeft(n);
    // dp[j] = [0, j]に含まれる種類数 + (j, i]に含まれる種類数の最大値
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> dp(n);
    vector<int> lastIndex(n+1, -1);
    for (int i = 0; i < n; ++i) {
        dp.apply(lastIndex[a[i]] == -1 ? 0 : lastIndex[a[i]], i, 1);
        ansLeft[i] = dp.prod(0, i);
        dp.set(i, l[i]);
        lastIndex[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        ans = max(ans, ansLeft[i] + r[i + 1]);
    }

    cout << ans << endl;
    return 0;
}