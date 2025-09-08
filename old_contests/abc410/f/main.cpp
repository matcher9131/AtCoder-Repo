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

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }

    // c[i][j]: 区画[i, i+1) x [0, j)におけるスコア
    vector<vector<int>> c(min(h, w), vector<int>(max(h, w) + 1));
    if (h <= w) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                c[i][j+1] = c[i][j] + (g[i][j] == '#' ? 1 : -1);
            }
        }
    } else {
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                c[i][j+1] = c[i][j] + (g[j][i] == '#' ? 1 : -1);
            }
        }
    }

    ll ans = 0;
    vector<int> cs(max(h, w) + 1);
    vector<int> csc(2*h*w+1);
    int offset = h*w;
    for (int i1 = 0; i1 < min(h, w); ++i1) {
        cs.assign(cs.size(), 0);
        for (int i2 = i1; i2 < min(h, w); ++i2) {
            for (int j = 0; j <= max(h, w); ++j) {
                cs[j] += c[i2][j];
                ans += csc[offset + cs[j]];
                ++csc[offset + cs[j]];
            }
            // reset csc
            for (int j = 0; j <= max(h, w); ++j) {
                --csc[offset + cs[j]];
            }
        }
    }

    cout << ans << endl;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}