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
using namespace atcoder;

bool op(bool x, bool y) { return x || y; }
bool e() { return false; }

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<segtree<bool, op, e>> tree(26, segtree<bool, op, e>(n));
    for (int i = 0; i < n; ++i) {
        tree[s[i] - 'a'].set(i, true);
    }

    for (int qi = 0; qi < q; ++qi) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            string sq;
            cin >> i >> sq;
            --i;
            tree[s[i] - 'a'].set(i, false);
            tree[sq[0] - 'a'].set(i, true);
            s[i] = sq[0];
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int ans = 0;
            for (int ci = 0; ci < 26; ++ci) {
                if (tree[ci].prod(l, r + 1)) ++ans;
            }
            cout << ans << endl;
        }
    }

    return 0;
}