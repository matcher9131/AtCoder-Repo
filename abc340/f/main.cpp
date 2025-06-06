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

ll extGcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main() {
    ll a, b;
    cin >> a >> b;
    if (a == 0) {
        if (b == 2 || b == -2) {
            cout << 1 << " " << 0 << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    } else if (b == 0) {
        if (a == 2 || a == -2) {
            cout << 0 << " " << 1 << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    ll g = gcd(a, b);
    if (g != 1 && g != 2) {
        cout << -1 << endl;
        return 0;
    }

    ll x, y;
    extGcd(b, -a, x, y);
    cout << 2 * x << " " << 2 * y << endl;

    return 0;
}