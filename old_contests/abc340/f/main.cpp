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

pair<ll, ll> ext_gcd(ll a, ll b) {
    if (b == 0) return { 1LL, 0 };
    auto [y, x] = ext_gcd(b, a % b);
    y -= a / b * x;
    return { x, y };
}

int main() {
    ll a, b;
    cin >> a >> b;
    
    if (a == 0) {
        if (abs(b) <= 2) {
            cout << 2 / abs(b) << " " << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    } else if (b == 0) {
        if (abs(a) <= 2) {
            cout << 0 << " " << 2 / abs(a) << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    ll g = gcd(a, b);
    if (g > 2) {
        cout << -1 << endl;
        return 0;
    }

    auto [x, y] = ext_gcd(b, -a);
    x = x * 2 / g;
    y = y * 2 / g;
    cout << x << " " << y << endl;

    return 0;
}