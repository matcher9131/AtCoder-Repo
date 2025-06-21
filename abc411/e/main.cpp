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
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

using S = mint;
S op(S a, S b) {
    return  a + b;
}
S e() {
    return 0;
}
using F = mint;
F mapping(F f, S x) {
    return f * x;
}
F composition(F f, F g) {
    return f * g;
}
F id() {
    return 1;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(6));
    vector<int> b(n*6);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> a[i][j];
            b[6*i+j] = a[i][j];
        }
        sort(a[i].begin(), a[i].end(), greater<int>());
    }
    b.push_back(0);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    vector<vector<int>> c(n, vector<int>(6));
    vector<int> revB(b.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            int bi = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin();
            c[i][j] = bi;
            revB[bi] = a[i][j];
        }
    }

    int m = b.size();
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(m);
    for (int i = 0; i < m; ++i) {
        seg.set(i, 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            seg.apply(j < 5 ? c[i][j+1] : 0, c[i][j], (mint)(5-j) / 6);
        }
    }

    mint ans = 0;
    for (int i = 1; i < m; ++i) {
        ans += (seg.get(i) - seg.get(i-1)) * revB[i];
    }

    cout << ans.val() << endl;

    return 0;
}