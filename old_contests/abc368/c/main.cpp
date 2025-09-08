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
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll t = 0;
    for (int i = 0; i < n; ++i) {
        if (t % 3 == 0) {
            ll numCycle = h[i] / 5LL;
            ll r = h[i] % 5LL;
            t += 3 * numCycle;
            t += r >= 3 ? 3 : r;
        } else if (t % 3 == 1) {
            if (h[i] == 1) {
                ++t;
            } else if (h[i] <= 4) {
                t += 2;
            } else {
                t += 2;
                h[i] -= 4;
                ll numCycle = h[i] / 5LL;
                ll r = h[i] % 5LL;
                t += 3 * numCycle;
                t += r >= 3 ? 3 : r;
            }
        } else {
            if (h[i] <= 3) {
                ++t;
            } else {
                ++t;
                h[i] -= 3;
                ll numCycle = h[i] / 5LL;
                ll r = h[i] % 5LL;
                t += 3 * numCycle;
                t += r >= 3 ? 3 : r;
            }
        }
    }

    cout << t << endl;

    return 0;
}