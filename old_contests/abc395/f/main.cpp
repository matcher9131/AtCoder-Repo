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
    ll x;
    cin >> n >> x;
    vector<ll> u(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i] >> d[i];
    }

    auto isOK = [&](ll h) -> bool {
        ll l = 0, r = h;
        for (int i = 0; i < n; ++i) {
            l = max({ 0LL, l - x, h - d[i] });
            r = min(r + x, u[i]);

            if (l > r) return false;
        }
        return true;
    };

    ll ng = 2e9 + 1;
    ll ok = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    cout << accumulate(u.begin(), u.end(), 0LL) + accumulate(d.begin(), d.end(), 0LL) - ok * n << endl;

    return 0;
}