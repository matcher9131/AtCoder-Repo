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
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        p[i] = { xi, yi };
    }
    sort(p.begin(), p.end());

    ll ans = 9e18;
    for (int xi = 0; xi < n; ++xi) {
        vector<ll> y;
        for (int xj = xi; xj < n; ++xj) {
            y.insert(lower_bound(y.begin(), y.end(), p[xj].second), p[xj].second);
            if ((int)y.size() < k) continue;
            for (int yi = 0; yi < (int)y.size() - k + 1; ++yi) {
                ans = min(ans, (p[xj].first - p[xi].first) * (y[yi+k-1] - y[yi]));
            }
        }
    }

    cout << ans << endl;
    return 0;
}