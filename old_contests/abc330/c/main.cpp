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
    ll d;
    cin >> d;

    ll ans = 1e18;
    for (ll x = 1; x * x <= d; ++x) {
        ll y = (ll)sqrt(d - x * x);
        ans = min(ans, abs(x*x + y*y - d));
        ans = min(ans, abs(x*x + (y+1)*(y+1) - d));
    }

    cout << ans << endl;
    return 0;
}