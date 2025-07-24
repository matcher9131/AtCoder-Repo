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

    ll sqrtn = sqrt(n);
    ll ans = 1;  // N=k
    // k <= √N: N = k^r(qk + 1)
    for (ll k = 2; k <= sqrtn; ++k) {
        ll m = n;
        while (m % k == 0) m /= k;
        if (m % k == 1) ++ans;
    }

    // k > √N: N = qk + 1
    for (ll p = 1; p <= sqrtn; ++p) {
        if ((n-1) % p == 0) {
            ll q = (n-1) / p;
            if (q > sqrtn) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}