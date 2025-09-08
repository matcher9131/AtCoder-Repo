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
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    ll x0 = 0, y0 = 0;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += sqrt((x[i] - x0) * (x[i] - x0) + (y[i] - y0) * (y[i] - y0));
        x0 = x[i];
        y0 = y[i];
    }
    ans += sqrt(x0 * x0 + y0 * y0);

    cout << setprecision(15) << ans << endl;

    return 0;
}