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
    ll a, b;
    cin >> n >> a >> b;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    auto isOK = [&](ll k) -> bool {
        ll numCenter = 0;
        for (int i = 0; i < n; ++i) {
            ll rest = h[i] - k * b;
            if (rest <= 0) continue;
            numCenter += (rest + a-b-1) / (a-b);
        }
        return numCenter <= k;
    };

    ll ng = 0;
    ll ok = 1e9;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}