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
using namespace std;
using ll = long long;

int n, m;
vector<ll> l;

bool isOK(ll w) {
    ll x = 0;
    int y = 1;
    for (const ll li : l) {
        if (li > w) return false;
        if (x + li > w) {
            ++y;
            if (y > m) return false;
            x = li + 1;
        } else {
            x += li + 1;
        }
    }
    return true;
}

ll binary_search() {
    ll ng = 0; 
    ll ok = 1e15;

    while (ok - ng > 1LL) {
        ll mid = ng + (ok - ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    return ok;
}

int main() {
    cin >> n >> m;
    l = vector<ll>(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    ll ans = binary_search();
    cout << ans << endl;

    return 0;
}
