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

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    int si = -1, sj = -1, ti = -1, tj = -1;
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (s[i][j] == 'T') {
                ti = i;
                tj = j;
            }
        }
    }
    int n;
    cin >> n;
    vector<tuple<int, int, int>> med(n);
    vector<vector<int>> medRev(h, vector<int>(w, -1));
    for (int i = 0; i < n; ++i) {
        int ri, ci, ei;
        cin >> ri >> ci >> ei;
        --ri;
        --ci;
        med[i] = { ri, ci, ei };
        medRev[ri][ci] = i;
    }
    if (medRev[si][sj] == -1) {
        cout << "No" << endl;
        return 0;
    }
    if (medRev[ti][tj] == -1) {
        med.emplace_back(ti, tj, 0);
        medRev[ti][tj] = n;
        ++n;
    }

    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    auto bfs = [&](int i, int j) -> vector<vector<int>> {
        vector<vector<int>> dist(h, vector<int>(w, INF));
        dist[i][j] = 0;
        queue<pair<int, int>> que;
        que.emplace(i, j);
        while (!que.empty()) {
            auto [ci, cj] = que.front();
            que.pop();
            for (const auto &[di, dj] : dir) {
                int ni = ci + di, nj = cj + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#') continue;
                if (dist[ni][nj] < INF) continue;
                dist[ni][nj] = dist[ci][cj] + 1;
                que.emplace(ni, nj);
            }
        }
        return dist;
    };
    
    vector<vector<int>> gm(n);
    for (int i = 0; i < n; ++i) {
        auto [ri, ci, ei] = med[i];
        auto dist = bfs(ri, ci);
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            auto [rj, cj, _] = med[j];
            if (dist[rj][cj] <= ei) {
                gm[i].push_back(j);
            }
        }
    }

    vector<bool> visited(n);
    function<void(int)> dfs = [&](int from) -> void {
        visited[from] = true;
        for (const int to : gm[from]) {
            if (visited[to]) continue;
            dfs(to);
        }
    };
    dfs(medRev[si][sj]);
    
    cout << (visited[medRev[ti][tj]] ? "Yes" : "No") << endl;

    return 0;
}