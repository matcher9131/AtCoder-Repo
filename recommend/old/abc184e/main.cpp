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

constexpr int INF = 1e8;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }

    int si, sj, gi, gj;
    vector<vector<pair<int, int>>> portal(26);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int c = a[i][j] - 'a';
            if (a[i][j] == 'S') si = i, sj = j;
            else if (a[i][j] == 'G') gi = i, gj = j;
            else if (c >= 0 && c < 26) portal[c].emplace_back(i, j);
        }
    }

    auto bfs = [&]() {
        vector<vector<int>> dist(h, vector<int>(w, INF));
        dist[si][sj] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
        que.emplace(0, si, sj);
        while (!que.empty()) {
            auto [d, i, j] = que.top();
            que.pop();
            if (dist[i][j] < d) continue;
            for (int dir = 0; dir < 4; ++dir) {
                int ni = i + dy[dir];
                int nj = j + dx[dir];
                if (ni == gi && nj == gj) return dist[i][j] + 1;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || a[ni][nj] == '#') continue;
                if (dist[ni][nj] > dist[i][j] + 1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    que.emplace(dist[ni][nj], ni, nj);
                }
            }
            int c = a[i][j] - 'a';
            if (c >= 0 && c < 26) {
                for (const auto &[ni, nj] : portal[c]) {
                    if (ni == i && nj == j) continue;
                    if (dist[ni][nj] > dist[i][j] + 1) {
                        dist[ni][nj] = dist[i][j] + 1;
                        que.emplace(dist[ni][nj], ni, nj);
                    }
                }
            }
        }
        return INF;
    };

    int ans = bfs();
    cout << (ans >= INF ? -1 : ans) << endl;

    return 0;
}