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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<bool>> terminal(h, vector<bool>(w));
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                terminal[i][j] = true;
                if (i > 0) terminal[i-1][j] = true;
                if (i < h-1) terminal[i+1][j] = true;
                if (j > 0) terminal[i][j-1] = true;
                if (j < w-1) terminal[i][j+1] = true;
            }
        }
    }

    int ans = 1;
    vector<vector<bool>> visited(h, vector<bool>(w));
    vector<bool> currentVisited(h * w);
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    function<void(int, int, int&)> dfs = [&](int i, int j, int &count) -> void {
        currentVisited[i * w + j] = true;
        visited[i][j] = true;
        ++count;
        if (terminal[i][j]) return;
        for (const auto& [di, dj] : dir) {
            int ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#' || currentVisited[ni * w + nj]) continue;
            dfs(ni, nj, count);
        }
    };

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (terminal[i][j] || visited[i][j]) continue;
            int count = 0;
            currentVisited.assign(h * w, false);
            dfs(i, j, count);
            ans = max(ans, count);
        }
    }

    cout << ans << endl;
    return 0;
}