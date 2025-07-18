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

// Slope trick
struct Slope {
    ll min;
    priority_queue<ll> l;
    priority_queue<ll, vector<ll>, greater<ll>> r;
};

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    auto numOp = [&](vector<ll> &v, ll size) -> ll {
        Slope s{0};
        s.l.push(v[0]);
        s.r.push(v[0] + size);
        for (ll i = 1; i < n; ++i) {
            // max(0, v[i] - x) の加算
            s.min += max(0LL, v[i] - s.r.top());
            s.r.push(v[i]);
            ll t1 = s.r.top();
            s.r.pop();
            s.l.push(t1);
            // max(0, x - (v[i] + size)) の加算
            s.min += max(0LL, s.l.top() - (v[i] + size));
            s.l.push(v[i] + size);
            ll t2 = s.l.top();
            s.l.pop();
            s.r.push(t2);
        }
        return s.min;
    };

    auto isOK = [&](ll size) -> bool {
        ll numOpX = numOp(x, size);
        ll numOpY = numOp(y, size);
        return numOpX + numOpY <= k;
    };

    ll ng = -1;
    ll ok = 1e9;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}