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
    vector<ll> ex, ey, ox, oy;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        if ((x + y) % 2) {
            ox.push_back(x + y);
            oy.push_back(x - y);
        } else {
            ex.push_back(x + y);
            ey.push_back(x - y);
        }
    }
    sort(ex.begin(), ex.end());
    sort(ey.begin(), ey.end());
    sort(ox.begin(), ox.end());
    sort(oy.begin(), oy.end());

    auto dist = [](vector<ll> &v) -> ll {
        ll ans = 0;
        int n = v.size();
        ll k = -(n - 1);
        for (int i = 0; i < n; ++i) {
            ans += k * v[i];
            k += 2;
        }
        return ans / 2;
    };

    cout << dist(ex) + dist(ey) + dist(ox) + dist(oy) << endl;

    return 0;
}