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
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 1 << endl;
        return 0;
    }
    if (a > b) swap(a, b);

    ll ans = 0;
    while (true) {
        ll g = gcd(a, b);
        a /= g;
        b /= g;
        if (b-a == 1) {
            ans += a;
            break;
        }

        ll d = b-a;
        ll r = 1e16;
        for (ll p = 2; p * p <= d; ++p) {
            if (d % p == 0) {
                r = min(r, b % p);
                r = min(r, b % (d / p));
            }
        }
        r = min(r, a % d);
        a -= r;
        b -= r;
        ans += r;
    }

    cout << ans << endl;
    return 0;
}