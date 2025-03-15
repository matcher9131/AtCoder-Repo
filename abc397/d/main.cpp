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

ll solve(ll a, ll b, ll c) {
    ll l = 0;
    ll r = 1e9;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (a * mid * mid + b * mid + c > 0) r = mid;
        else l = mid;
    }

    return a * l * l + b * l + c == 0 ? l : -1;
}

int main() {
    ll n;
    cin >> n;

    for (ll p = 1; p * p * p < n; ++p) {
        if (n % p != 0) continue;
        ll q = n / p;
        ll ans = solve(3, 3 * p, p * p - q);
        if (ans != -1) {
            cout << ans + p << " " << ans << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}