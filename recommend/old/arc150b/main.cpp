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

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b) {
        cout << a-b << endl;
        return;
    }

    ll ans = 1e16;
    ll a0 = a;
    while (a <= b) {
        if (a - a0 >= ans) break;
        ll q = b / a;
        ll r = b % a;
        ll y = r == 0 ? 0 : a-r;
        ans = min(ans, a-a0 + y);
        if (r < q) ++a;
        else a += r / q;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}