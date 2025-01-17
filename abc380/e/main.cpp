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
    int n, nq;
    cin >> n >> nq;
    vector<tuple<int, int, int>> q(nq);
    for (int i = 0; i < nq; ++i) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, c;
            cin >> x >> c;
            // --x;
            q[i] = make_tuple(k, x, c);
        } else {
            int c;
            cin >> c;
            q[i] = make_tuple(k, c, 0);
        }
    }

    vector<int> nc(n + 2, 1);
    // key = 連結部分の右端セル番号(1-indexed), value = 色
    map<int, int> m;
    // 番兵を含める
    for (int i = 0; i <= n + 1; ++i) {
        m[i] = i;
    }

    for (const auto& [k, x, c] : q) {
        if (k == 1) {
            auto it = m.lower_bound(x);
            auto rit = it, lit = it;
            ++rit; --lit;
            auto [rx, rc] = *rit;
            auto [cx, cc] = *it;
            auto [lx, lc] = *lit;
            int size = cx - lx;
            nc[cc] -= size;
            nc[c] += size;
            it->second = c;
            if (lc == c) {
                m.erase(lx);
            }
            if (rc == c) {
                m.erase(cx);
            }
        } else {
            cout << nc[x] << endl;
        }
    }

    return 0;
}