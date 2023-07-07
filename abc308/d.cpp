#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using int64 = long long;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const string SNUKE = "snuke";

void dfs(const vector<string>& map, vector<vector<bool>>& visited, int r, int c, const int h, const int w, int i) {
    visited[r][c] = true;
    if (r == h - 1 && c == w - 1) return;

    for (int dir = 0; dir < 4; dir++)
    {
        int nr = r + dy[dir];
        int nc = c + dx[dir];
        if (nr < 0 || nr >= h || nc < 0 || nc >= w || visited[nr][nc]) continue;
        char ch = SNUKE[(i + 1) % 5];
        if (map[nr][nc] != ch) continue;
        dfs(map, visited, nr, nc, h, w, i + 1);
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    if (s[0][0] != 's') {
        cout << "No" << endl;
        return 0;
    }
    
    vector<vector<bool>> visited(h, vector<bool>(w));
    dfs(s, visited, 0, 0, h, w, 0);
    cout << (visited[h - 1][w - 1] ? "Yes" : "No") << endl;
    
    return 0;
}