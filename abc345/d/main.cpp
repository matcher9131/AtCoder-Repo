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
    int n, h, w;
    cin >> n >> h >> w;
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        t[i] = { ai, bi };
    }
    sort(t.begin(), t.end());

    auto isClear = [&](vector<bool>& g, int rStart, int cStart, int r, int c) -> bool {
        if (any_of(g.begin() + rStart * w + cStart, g.begin() + rStart * w + cStart + c, [](bool x) { return x; })) return false;
        if (any_of(g.begin() + (rStart + r - 1) * w + cStart, g.begin() + (rStart + r - 1) * w + cStart + c, [](bool x) { return x; })) return false;
        for (int ri = 1; ri < r - 1; ++ri) {
            if (g[(rStart + ri) * w + cStart]) return false;
            if (g[(rStart + ri) * w + cStart + c - 1]) return false;
        }
        return true;
    };

    auto fits = [&](int bit) -> bool {
        vector<bool> g(h * w);
        for (int i = 0; i < n; ++i) {
            int si = 0;
            while (g[si]) ++si;
            int rStart = si / w, cStart = si % w;
            auto [r, c] = t[i];
            if (bit & (1 << i)) swap(r, c);
            if (rStart + r > h || cStart + c > w) continue;
            if (isClear(g, rStart, cStart, r, c)) {
                for (int ri = 0; ri < r; ++ri) {
                    for (int ci = 0; ci < c; ++ci) {
                        g[(rStart + ri) * w + cStart + ci] = true;
                    }
                }
            }
        }
        return all_of(g.begin(), g.end(), [](bool x) { return x; });
    };

    do {
        for (int bit = 0; bit < (1 << n); ++bit) {
            if (fits(bit)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    } while (next_permutation(t.begin(), t.end()));

    cout << "No" << endl;
    return 0;
}