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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll c = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return c;
}

ll divFloor(ll x, ll y) {
    if (x % y == 0) return x / y;
    if (x >= 0) return x / y;
    else return -((-x) / y) - 1LL;
}

ll divCeil(ll x, ll y) {
    if (x % y == 0) return x / y;
    if (x >= 0) return x / y + 1LL;
    else return -((-x) / y);
}

int main() {
    ll n, a0, b0, c0, x;
    cin >> n >> a0 >> b0 >> c0 >> x;

    ll gbc = gcd(b0, c0);
    ll answer = 0;
    for (int i = 1; i <= n; ++i) {
        ll y = x - a0 * i;
        if (y < 0) break;
        // yがgcd(b, c)で割り切れないときは解なし
        if (y % gbc > 0) continue;
        ll gbcy = gcd(y, gbc);
        ll b = b0 / gbcy;
        ll c = c0 / gbcy;
        y /= gbcy;
        ll j0, k0;
        extgcd(b, c, j0, k0);
        j0 *= y % b;
        k0 *= y % b;
        j0 += y / b;
        // j = cm + j0, k = -bm + k0
        // 1 <= cm + j0 <= n, 1 <= -bm + k0 <= n
        // (1 - j0) / c <= m <= (n - j0) / c, (k0 - n) / b <= m <= (k0 - 1) / b
        ll mjmin = divCeil(1 - j0, c);
        ll mjmax = divFloor(n - j0, c);
        ll mkmin = divCeil(k0 - n, b);
        ll mkmax = divFloor(k0 - 1, b);
        ll mmin = max(mjmin, mkmin);
        ll mmax = min(mjmax, mkmax);
        if (mmax >= mmin) answer += mmax - mmin + 1;
    }

    cout << answer << endl;

    return 0;
}