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
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        ai %= m;
        ans += (i + 1) * (n - i) * ai;
    }

    cout << ans << endl;

    return 0;
}