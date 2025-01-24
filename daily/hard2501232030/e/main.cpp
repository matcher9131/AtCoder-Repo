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
    ll n;
    cin >> n;

    ll bMax = (ll)sqrt(n);
    ll ans = 0;
    for (ll b = 1; b <= bMax; ++b) {
        ll m = n / b;
        ll aMax = min(b, (ll)sqrt(m));
        for (ll a = 1; a <= aMax; ++a) {
            ll c = m / a;
            if (c >= b && c >= a) ans += c - b + 1;
        }
    }

    cout << ans << endl;

    return 0;
}