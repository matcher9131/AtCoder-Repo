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

ll divCeil(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    ll sx = x[0], sy = y[0];
    for (int i = 1; i < n; ++i) {
        ll rx = divCeil(sx, x[i]);
        ll ry = divCeil(sy, y[i]);
        ll r = max(rx, ry);
        sx = r * x[i];
        sy = r * y[i];
    }

    cout << sx + sy << endl;

    return 0;
}