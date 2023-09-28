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
    int k;
    cin >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    auto isOK = [&](ll n, bool isLeft){
        for (int i = 0; i < k; ++i) {
            n = n / a[i] * a[i];
        }
        return isLeft ? n >= 2 : n <= 2;
    };

    function<ll()> binary_search_left = [&]() {
        ll ng = 1;
        ll ok = 1e18;

        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (isOK(mid, true)) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    function<ll()> binary_search_right = [&]() {
        ll ng = 1e18;
        ll ok = 1;

        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (isOK(mid, false)) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    ll l = binary_search_left();
    ll r = binary_search_right();

    if (l > r) {
        cout << -1 << endl;
    } else {
        cout << l << " " << r << endl;
    }

    return 0;
}