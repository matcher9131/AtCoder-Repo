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
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    if (tx >= sx) {
        ll sxr = (sx + sy) % 2 == 0 ? sx + 1 : sx;
        ll xr = sxr + abs(ty - sy);
        if (tx > xr) {
            cout << abs(ty - sy) + (tx - xr + 1) / 2 << endl;
        } else {
            cout << abs(ty - sy) << endl;
        }
    } else {
        ll sxl = (sx + sy) % 2 == 0 ? sx : sx - 1;
        ll xl = sxl - abs(ty - sy);
        if (tx < xl) {
            cout << abs(ty - sy) + (xl - tx + 1) / 2 << endl;
        } else {
            cout << abs(ty - sy) << endl;
        }
    }

    return 0;
}