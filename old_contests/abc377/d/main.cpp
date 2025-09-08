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
    // Li, Ri
    vector<pair<ll, ll>> segments;
    // l <= Liを満たす(Li, i)
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> left;
    // l <= Liを満たす(Ri, i)
    set<pair<ll, int>> right;
    for (int i = 0; i < n; ++i) {
        ll li, ri;
        cin >> li >> ri;
        segments.emplace_back(li, ri);
        left.emplace(li, i);
        right.emplace(ri, i);
    }

    ll ans = 0;
    for (ll l = 1; l <= m; ++l) {
        while (!left.empty()) {
            auto [li, i] = left.top();
            if (l <= li) break;
            left.pop();
            right.erase(make_pair(segments[i].second, i));
        }
        // [l, r)
        ll r = right.empty() ? m + 1 : right.begin()->first;
        ans += r - l;
    }

    cout << ans << endl;

    return 0;
}