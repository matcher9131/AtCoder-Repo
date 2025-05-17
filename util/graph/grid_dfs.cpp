#include <vector>
#include <string>
#include <functional>
using namespace std;
extern int h, w;
extern vector<string> s;


vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<bool>> visited(h, vector<bool>(w));
function<void(int, int)> dfs = [&](int i, int j) -> void {
    visited[i][j] = true;
    for (const auto &[di, dj] : dir) {
        int ni = i + di, nj = j + dj;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#' || visited[ni][nj]) continue;
        dfs(ni, nj);
    }
};
