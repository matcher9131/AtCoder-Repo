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
S op(S a, S b) { return max(a, b); }
S e() { return 0; }
using F = int;
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        s[i] = make_pair(ai, bi);
    }
    sort(s.begin(), s.end());

    int right = 0;
    int ans = 0;
    // seg[i] = 体重が区間[i, i+k]に属する人数
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(5001);
    for (int left = 0; left < n; ++left) {
        while (right < n && s[right].first - s[left].first <= k) {
            int bi = s[right].second;
            // i <= bi <= i + k ⇔ bi - k <= i <= bi
            seg.apply(max(0, bi - k), bi + 1, 1);
            ++right;
        }

        ans = max(ans, seg.all_prod());

        if (right == left) {
            ++right;
        } else {
            int bi = s[left].second;
            seg.apply(max(0, bi - k), bi + 1, -1);
        }
    }

    cout << ans << endl;

    return 0;
}