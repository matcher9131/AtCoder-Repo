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

const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }

    vector<vector<bool>> visited(h, vector<bool>(w));
    function<void(int, int)> dfs = [&](int i, int j) {
        visited[i][j] = true;
        for (int dir = 0; dir < 8; ++dir) {
            int ni = i + dy[dir];
            int nj = j + dx[dir];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (visited[ni][nj] || g[ni][nj] != '#') continue;
            dfs(ni, nj);
        }
    };

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && g[i][j] == '#') {
                dfs(i, j);
                ++ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}