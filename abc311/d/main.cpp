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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
 
int h, w;
vector<string> g;
vector<vector<bool>> visited;
vector<vector<int>> moved;
void dfs(int i, int j) {
    for (int dir = 0; dir < 4; ++dir) {
        if (moved[i][j] & (1 << dir)) continue;
 
        int ni = i, nj = j;
        for (; g[ni][nj] == '.'; ni += dy[dir], nj += dx[dir]) {
            visited[ni][nj] = true;
        }
        ni -= dy[dir];
        nj -= dx[dir];
        moved[i][j] |= 1 << dir;
 
        dfs(ni, nj);
    }
}
 
int main() {
    cin >> h >> w;
    g = vector<string>(h);
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }
    visited = vector<vector<bool>>(h, vector<bool>(w));
    moved = vector<vector<int>>(h, vector<int>(w));
    visited[1][1] = true;
    
    dfs(1, 1);
 
    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (visited[i][j]) ++count;
        }
    }
 
    cout << count << endl;
 
    return 0;
}