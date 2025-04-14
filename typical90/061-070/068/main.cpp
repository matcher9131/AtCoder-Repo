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

// sum, length
using S = pair<ll, int>;
S op(S a, S b) {
    return { a.first + (a.second % 2 == 0 ? 1 : -1) * b.first, a.second + b.second };
}
S e() {
    return { false, 0 };
}

int main() {
    int n, nq;
    cin >> n >> nq;
    atcoder::segtree<S, op, e> seg(n);

    while (nq--) {
        int t, x, y, v;
        cin >> t >> x >> y >> v;
        --x;
        --y;
        if (t == 0) {
            seg.set(x, { v, 1 });
        } else {
            bool swapped = false;
            if (x > y) {
                swap(x, y);
                swapped = true;
            }

            auto [altsum, length] = seg.prod(x, y);
            if (length != y - x) {
                cout << "Ambiguous" << endl;
            } else if ((y - x) % 2) {
                cout << altsum - v << endl;
            } else {
                cout << (swapped ? altsum : -altsum) + v << endl;
            }
        }
    }

    return 0;
}