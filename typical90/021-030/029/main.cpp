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
using namespace atcoder;

int op(int x, int y) {
    return max(x, y);
}
int e() {
    return 0;
}
int setValue = 0;
int mapping(int f, int x) {
    return max(f, x);
}
int composition(int f, int g) {
    return max(f, g);
}
int id() {
    return 0;
}

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
    }

    lazy_segtree<int, op, e, int, mapping, composition, id> tree(w);
    for (int i = 0; i < n; ++i) {
        int h = tree.prod(l[i], r[i]);
        tree.apply(l[i], r[i], h + 1);
        cout << h + 1 << endl;
    }

    return 0;
}