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

constexpr ll INF = 1e18;
constexpr ll MAGIC_COST = 1e9;

int main() {
    vector<pair<int, int>> next = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }};

    int h, w;
    cin >> h >> w;
    int si, sj;
    cin >> si >> sj;
    --si; --sj;
    int gi, gj;
    cin >> gi >> gj;
    --gi; --gj;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    dist[si][sj] = 0;
    // dist, i, j
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> que;
    que.emplace(0, si, sj);
    while (!que.empty()) {
        auto [d, i, j] = que.top();
        que.pop();
        if (i == gi && j == gj) {
            cout << d / MAGIC_COST << endl;
            return 0;
        }

        if (d > dist[i][j]) continue;

        for (const auto& [di, dj] : next) {
            int ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#') continue;
            ll nc = dist[i][j] + 1;
            if (nc < dist[ni][nj]) {
                dist[ni][nj] = nc;
                que.emplace(nc, ni, nj);
            }
        }
        for (int di = -2; di <= 2; ++di) {
            for (int dj = -2; dj <= 2; ++dj) {
                if (di == 0 && dj == 0) continue;
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#') continue;
                ll nc = dist[i][j] + MAGIC_COST;
                if (nc < dist[ni][nj]) {
                    dist[ni][nj] = nc;
                    que.emplace(nc, ni, nj);
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}