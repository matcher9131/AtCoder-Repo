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

constexpr ll INF = 1e16;

int main() {
    int n, k;
    ll p;
    cin >> n >> p >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    auto numPath = [&](ll x) -> int {
        vector<vector<ll>> d = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][j] == -1) d[i][j] = x;
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (d[i][j] <= p) ++count;
            }
        }

        return count;
    };

    ll xMin = ([&]() -> ll {
        ll ng = 0;
        ll ok = INF;

        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (numPath(mid) <= k) ok = mid;
            else ng = mid;
        }
        return ok;
    })();

    ll xMax = ([&]() -> ll {
        ll ng = INF;
        ll ok = 0;

        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (numPath(mid) >= k) ok = mid;
            else ng = mid;
        }
        return ok;
    })();

    if (xMax >= INF - 1) {
        cout << (xMin >= INF ? "0" : "Infinity") << endl;
    } else {
        cout << xMax - xMin + 1 << endl;
    }

    return 0;
}