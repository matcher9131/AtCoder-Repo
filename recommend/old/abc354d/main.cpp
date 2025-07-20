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

int mfloor(int x, int y) {
    int ans = x / y * y;
    return x >= 0 ? ans : ans - y;
}

int main() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll l = mfloor(x1, 4), r = mfloor(x2, 4);
    ll d = mfloor(y1, 2), u = mfloor(y2, 2);
    
    ll ans = ((r - l) / 4) * ((u - d) / 2) * 8;

    vector<vector<ll>> map = {
        {0, 0, 0},
        {0, 2, 3},
        {0, 3, 6},
        {0, 3, 7},
        {0, 4, 8},
    };

    ans -= ((u - d) / 2) * map[x1 - l][2];
    ans -= ((r - l) / 4) * map[4][y1 - d];
    ans += map[x1 - l][y1 - d];

    ans += ((r - l) / 4) * map[4][y2 - u];
    ans -= map[x1 - l][y2 - u];
    ans += ((u - d) / 2) * map[x2 - r][2];
    ans -= map[x2 - r][y1 - d];
    ans += map[x2 - r][y2 - u];

    cout << ans << endl;
    return 0;
}