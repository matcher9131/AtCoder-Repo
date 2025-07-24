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
    ll n, c;
    cin >> n >> c;
    vector<ll> x(n), y(n), v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> v[i];
        y[n-1-i] = c - x[i];
    }
    x.insert(x.begin(), 0);
    y.insert(y.begin(), 0);

    vector<ll> scw(n+1), sccw(n+1);
    for (ll i = 0; i < n; ++i) {
        scw[i+1] = scw[i] + v[i];
        sccw[i+1] = sccw[i] + v[n-1-i];
    }
    for (ll i = 0; i <= n; ++i) {
        scw[i] -= x[i];
        sccw[i] -= y[i];
    }
    vector<ll> mscw(n+1), msccw(n+1);
    mscw[0] = scw[0];
    msccw[0] = msccw[0];
    for (ll i = 1; i <= n; ++i) {
        mscw[i] = max(mscw[i-1], scw[i]);
        msccw[i] = max(msccw[i-1], sccw[i]);
    }

    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        ll rest = c - 2 * x[i];
        if (rest <= 0) break;
        ll j = upper_bound(y.begin(), y.end(), rest) - y.begin() - 1;
        ans = max(ans, scw[i] - x[i] + msccw[j]);
    }
    for (ll i = 0; i <= n; ++i) {
        ll rest = c - 2 * y[i];
        if (rest <= 0) break;
        ll j = upper_bound(x.begin(), x.end(), rest) - x.begin() - 1;
        ans = max(ans, sccw[i] - y[i] + mscw[j]);
    }
    
    cout << ans << endl;

    return 0;
}