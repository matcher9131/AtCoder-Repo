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
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
        --x[i];
    }

    ll ans = 0;
    vector<ll> cost(n);
    for (int j = 1; j < m; ++j) {
        int from = x[j-1], to = x[j];
        int cw = (to + n - from) % n;
        int ccw = n - cw;
        ans += min(cw, ccw);
        if (cw < ccw) {
            int d = ccw - cw;
            if (from < to) {
                cost[from] += d;
                cost[to] -= d;
            } else {
                cost[from] += d;
                cost[0] += d;
                cost[to] -= d;
            }
        } else if (cw > ccw) {
            int d = cw - ccw;
            if (from > to) {
                cost[to] += d;
                cost[from] -= d;
            } else {
                cost[to] += d;
                cost[0] += d;
                cost[from] -= d;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cost[i] += cost[i-1];
    }

    cout << ans + *min_element(cost.begin(), cost.end()) << endl;

    return 0;
}