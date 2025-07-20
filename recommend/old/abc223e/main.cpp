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

ll div_ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    ll x, y;
    cin >> x >> y;
    vector<ll> a(3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // 縦→縦
    ll sw = 0;
    for (int i = 0; i < 3; ++i) {
        sw += div_ceil(a[i], y);
        if (sw > x) break;
    }
    if (sw <= x) {
        cout << "Yes" << endl;
        return 0;
    }
    // 縦→横
    for (int i = 0; i < 3; ++i) {
        ll w = div_ceil(a[i], y);
        if (w >= x) continue;
        ll h = div_ceil(a[(i+1) % 3], x-w) + div_ceil(a[(i+2) % 3], x-w);
        if (h <= y) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    // 横→横
    ll sh = 0;
    for (int i = 0; i < 3; ++i) {
        sh += div_ceil(a[i], x);
        if (sh > y) break;
    }
    if (sh <= y) {
        cout << "Yes" << endl;
        return 0;
    }
    // 横→縦
    for (int i = 0; i < 3; ++i) {
        ll h = div_ceil(a[i], x);
        if (h >= y) continue;
        ll w = div_ceil(a[(i+1) % 3], y-h) + div_ceil(a[(i+2) % 3], y-h);
        if (w <= x) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}