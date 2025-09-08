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

ll floor(ll x, ll y) {
    return x >= 0 ? x / y : x / y - 1;
}

int main() {
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;

    ll l = floor(px, 4) * 4;
    ll d = floor(py, 2) * 2;
    ll r = floor(qx, 4) * 4;
    ll u = floor(qy, 2) * 2;
    ll xc = (r - l) / 4;
    ll yc = (u - d) / 2;

    ll ans = xc * yc * 8;

    vector<vector<int>> map{
        {0, 0, 0},
        {0, 2, 3},
        {0, 3, 6},
        {0, 3, 7},
        {0, 4, 8},
    };

    ans -= xc * map[4][py - d];
    ans -= yc * map[px - l][2];
    ans += map[px - l][py - d];
    ans += xc * map[4][qy - u];
    ans -= map[px - l][qy - u];
    ans += yc * map[qx - r][2];
    ans -= map[qx - r][py - d];
    ans += map[qx - r][qy - u];

    cout << ans << endl;
    return 0;
}