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
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    ll tl = abs(xa - (xb - 1)) + abs(ya - yb) + (ya == yb && xa > xb ? 2 : 0);
    ll tr = abs(xa - (xb + 1)) + abs(ya - yb) + (ya == yb && xa < xb ? 2 : 0);
    ll tb = abs(xa - xb) + abs(ya - (yb - 1)) + (xa == xb && ya > yb ? 2 : 0);
    ll tt = abs(xa - xb) + abs(ya - (yb + 1)) + (xa == xb && ya < yb ? 2 : 0);

    ll ans = 1e18;
    ll d = abs(xb - xc) + abs(yb - yc);
    if (xb < xc) {
        if (yb < yc) {
            // 右上
            ans = min(ans, tl + d + 2);
            ans = min(ans, tb + d + 2);
        } else if (yb > yc) {
            // 右下
            ans = min(ans, tl + d + 2);
            ans = min(ans, tt + d + 2);
        } else {
            // 右
            ans = min(ans, tl + d);
        }
    } else if (xb > xc) {
        if (yb < yc) {
            // 左上
            ans = min(ans, tr + d + 2);
            ans = min(ans, tb + d + 2);
        } else if (yb > yc) {
            // 左下
            ans = min(ans, tr + d + 2);
            ans = min(ans, tt + d + 2);
        } else {
            // 左
            ans = min(ans, tr + d);
        }
    } else {
        if (yb < yc) {
            // 上
            ans = min(ans, tb + d);
        } else if (yb > yc) {
            // 下
            ans = min(ans, tt + d);
        } else {
            assert(false);
        }
    }

    cout << ans << endl;

    return 0;
}