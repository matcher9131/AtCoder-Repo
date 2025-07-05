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
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<ll>> g(h, vector<ll>(w, -1));
    vector<vector<int>> next(h, vector<int>(w));
    queue<pair<int, int>> que;
    for (int ki = 0; ki < k; ++ki) {
        int ri, ci;
        cin >> ri >> ci;
        --ri;
        --ci;
        g[ri][ci] = 0;
        for (const auto &[di, dj] : dir) {
            int ni = ri + di, nj = ci + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            ++next[ni][nj];
            if (next[ni][nj] == 2) que.emplace(ni, nj);
        }
    }

    
    auto secondSmallest = [&](int i, int j) -> ll {
        ll s1 = INF, s2 = INF;
        for (const auto &[di, dj] : dir) {
            int ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || g[ni][nj] == -1) continue;
            if (g[ni][nj] < s1) {
                s2 = s1;
                s1 = g[ni][nj];
            } else if (g[ni][nj] < s2) {
                s2 = g[ni][nj];
            }
        }
        return s2;
    };

    
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        if (g[i][j] >= 0) continue;

        ll ss = secondSmallest(i, j);
        if (ss < INF) {
            g[i][j] = ss + 1;
            // printf("g[%d][%d] = %lld\n", i, j, ss+1);
            for (const auto &[di, dj] : dir) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || g[ni][nj] >= 0) continue;
                ++next[ni][nj];
                if (next[ni][nj] == 2) que.emplace(ni, nj);
            }
        }
    }


    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i][j] >= 0 && g[i][j] < INF) ans += g[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}