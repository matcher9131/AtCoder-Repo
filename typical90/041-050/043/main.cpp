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
    int h, w, si, sj, gi, gj;
    cin >> h >> w >> si >> sj >> gi >> gj;
    --si;
    --sj;
    --gi;
    --gj;
    vector<string> g(h);
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }

    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(4, INF)));
    dist[si][sj][0] = 0;
    dist[si][sj][1] = 0;
    dist[si][sj][2] = 0;
    dist[si][sj][3] = 0;
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> que;
    que.emplace(0, 0, si, sj);
    que.emplace(0, 1, si, sj);
    que.emplace(0, 2, si, sj);
    que.emplace(0, 3, si, sj);
    while (!que.empty()) {
        auto [d, prevDir, i, j] = que.top();
        que.pop();
        if (d > dist[i][j][prevDir]) continue;
        for (int dir = 0; dir < 4; ++dir) {
            int ni = i + dy[dir];
            int nj = j + dx[dir];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || g[ni][nj] == '#') continue;
            int nd = dist[i][j][prevDir] + (dir == prevDir ? 0 : 1);
            if (dist[ni][nj][dir] > nd) {
                dist[ni][nj][dir] = nd;
                que.emplace(nd, dir, ni, nj);
            }
        }
    }

    cout << *min_element(dist[gi][gj].begin(), dist[gi][gj].end()) << endl;

    return 0;
}