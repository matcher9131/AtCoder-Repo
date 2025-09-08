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

constexpr double INF = 1e20;
using S = double;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> x(n+1), y(n+1);
    cin >> x[n] >> y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    auto dist = [&](int i, int j) -> double {
        double dx = x[j] - x[i];
        double dy = y[j] - y[i];
        return sqrt(dx*dx + dy*dy);
    };

    atcoder::segtree<S, op, e> seg(k);
    seg.set(k-1, 0);
    for (int i = 0; i < n-1; ++i) {
        int ki = i % k;
        double minDist = seg.all_prod();
        if (minDist < INF) {
            seg.set(ki, minDist + dist(i, n) + dist(n, i+1) - dist(i, i+1));
        }
    }

    double ans = dist(n, 0);
    for (int i = 0; i < n; ++i) {
        ans += dist(i, i+1);
    }

    cout << setprecision(15) << ans + seg.all_prod() << endl;

    return 0;
}