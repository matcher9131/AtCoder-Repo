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

bool inline isInBigChunk(ll cx, ll cy) {
    return (cx % 2 == 1) ^ (cy % 2 == 1);
};

int main() {
    ll k, sx, sy, tx, ty;
    cin >> k >> sx >> sy >> tx >> ty;

    if (k == 1) {
        cout << abs(tx - sx) + abs(ty - sy) << endl;
        return 0;
    }

    auto getNearestBigChunks = [&](ll x, ll y) -> vector<tuple<ll, ll, ll>> {
        vector<tuple<ll, ll, ll>> result;
        ll cx = x / k, cy = y / k;
        if (isInBigChunk(cx, cy)) {
            result.emplace_back(cx, cy, 0);
        } else {
            result.emplace_back(cx + 1, cy, k - x % k);
            result.emplace_back(cx, cy + 1, k - y % k);
            result.emplace_back(cx - 1, cy, x % k + 1);
            result.emplace_back(cx, cy - 1, y % k + 1);
        }
        return result;
    };
    
    // cx, cy, dist
    vector<tuple<ll, ll ,ll>> sc = getNearestBigChunks(sx, sy);
    vector<tuple<ll, ll ,ll>> tc = getNearestBigChunks(tx, ty);

    ll ans = abs(tx - sx) + abs(ty - sy);
    for (const auto &[scx, scy, sd] : sc) {
        for (const auto &[tcx, tcy, td] : tc) {
            ll dcx = abs(tcx - scx), dcy = abs(tcy - scy);
            ll d = sd + td + dcx + dcy + abs(dcx - dcy) / (k == 2 ? 2 : 1);
            ans = min(ans, d);
        }
    }

    cout << ans << endl;
    return 0;
}