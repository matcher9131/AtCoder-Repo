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
    int n;
    cin >> n;
    vector<int> p(n), q(n), revQ(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        revQ[q[i]] = i;
    }

    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k * p[i] <= n; ++k) {
            if (revQ[k * p[i]] != -1) {
                pairs.emplace_back(i, -revQ[k * p[i]]);
            }
        }
    }
    sort(pairs.begin(), pairs.end());

    vector<int> dp;
    for (const auto& [_, qi] : pairs) {
        auto dst = lower_bound(dp.begin(), dp.end(), -qi);
        if (dst == dp.end()) {
            dp.push_back(-qi);
        } else {
            *dst = -qi;
        }
    }

    cout << dp.size() << endl;
    return 0;
}