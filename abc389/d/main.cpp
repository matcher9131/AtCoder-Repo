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

// (x, 0)を中心とする正方形が円内にあるか(x >= 0, y >= 0)
bool isOK(ll r, ll x, ll y) {
    double dx = x + 0.5;
    double dy = y + 0.5;
    return dx * dx + dy * dy <= r * r;
}

// (x, y)を中心とする正方形が円内にあるようなxの最大値
ll binary_search(ll r, ll y) {
    ll ok = 0;
    ll ng = r;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(r, mid, y)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll r;
    cin >> r;

    ll ansAxis = binary_search(r, 0);
    ll ansNoAxis = 0;
    for (ll y = 1; y <= r; ++y) {
        ll count = binary_search(r, y);
        ansNoAxis += count;
    }
    // 中央はまだカウントしていない
    ll ans = 4LL * ansNoAxis + 4 * ansAxis + 1;

    cout << ans << endl;

    return 0;
}