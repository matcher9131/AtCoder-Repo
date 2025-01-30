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
    ll k;
    cin >> k;

    ll ans = 0;
    ll aMax = ceil(pow(k, 0.34));
    for (ll a = 0; a <= aMax; ++a) {
        ll bMax = ceil(pow((double)k / a, 0.5));
        for (ll b = a; b <= bMax; ++b) {
            if (k % (a * b) > 0) continue;
            ll c = k / (a * b);
            if (c < b) break;
            if (k % c == 0) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}