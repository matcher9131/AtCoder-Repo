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

constexpr ll INF = 1e18;

ll op(ll x, ll y) {
    return min(x, y);
}

ll e() {
    return INF;
}

ll target;
bool f(ll v) {
    return v > target;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> t(m), w(m), s(m);
    for (int i = 0; i < m; ++i) {
        cin >> t[i] >> w[i] >> s[i];
    }

    vector<ll> v(n);
    segtree<ll, op, e> seg(v);
    target = 0;
    vector<ll> sum(n);
    for (int i = 0; i < m; ++i) {
        target = t[i];
        int j = seg.max_right<f>(0);
        if (j < n) {
            sum[j] += w[i];
            seg.set(j, t[i] + s[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << sum[i] << endl;
    }


    return 0;
}