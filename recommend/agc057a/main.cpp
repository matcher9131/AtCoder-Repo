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

int numDigits(ll x) {
    int res = 0;
    while (x > 0) {
        x /= 10;
        ++res;
    }
    return res;
}

ll minParent(ll x) {
    return min(10 * x, (ll)pow(10, numDigits(x)) + x);
}

void solve() {
    ll l, r;
    cin >> l >> r;
    
    ll ok = r;
    ll ng = l-1;
    while (ok - ng > 1) {
        ll mid = (ok+ng) / 2;
        if (minParent(mid) > r) ok = mid;
        else ng = mid;
    }
    cout << r - ok + 1 << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}