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
using namespace std;
using ll = long long;

constexpr int INF = 1e7;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int h, w;
vector<string> g;
vector<vector<int>> dist;

int dikjstra(int si, int sj, int gi, int gj) {
    dist[si][sj] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
    que.emplace(0, si, sj);
    while (!que.empty()) {
        auto [d, i, j] = que.top();
        que.pop();
        if (i == gi && j == gj) return d;
        if (dist[i][j] < d) continue;
        for (int dir = 0; dir < 4; ++dir) {
            int ni = i + dy[dir];
            int nj = j + dx[dir];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (g[ni][nj] != '.') continue;
            if (dist[ni][nj] > dist[i][j] + 1) {
                dist[ni][nj] = dist[i][j] + 1;
                que.emplace(dist[ni][nj], ni, nj);
            }
        }
    }
    return -1;
}

int main() {
    cin >> h >> w;
    g = vector<string>(h);
    dist = vector<vector<int>>(h, vector<int>(w, INF));
    int si, sj, gi, gj;
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
        for (int j = 0; j < w; ++j) {
            if (g[i][j] == 'S') {
                si = i;
                sj = j;
                g[i][j] = '.';
            } else if (g[i][j] == 'G') {
                gi = i;
                gj = j;
                g[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        int rj = w;
        for (int j = 0; j < w; ++j) {
            if (g[i][j] == '>') rj = j;
            else if (g[i][j] == '.' || g[i][j] == '!') {
                if (j > rj) g[i][j] = '!';
            } else rj = w;
        }
        int lj = -1;
        for (int j = w - 1; j >= 0; --j) {
            if (g[i][j] == '<') lj = j;
            else if (g[i][j] == '.' || g[i][j] == '!') {
                if (j < lj) g[i][j] = '!';
            } else lj = -1;
        }
    }
    for (int j = 0; j < w; ++j) {
        int di = h;
        for (int i = 0; i < h; ++i) {
            if (g[i][j] == 'v') di = i;
            else if (g[i][j] == '.' || g[i][j] == '!') {
                if (i > di) g[i][j] = '!';
            } else di = h;
        }
        int ui = -1;
        for (int i = h - 1; i >= 0; --i) {
            if (g[i][j] == '^') ui = i;
            else if (g[i][j] == '.' || g[i][j] == '!') {
                if (i < ui) g[i][j] = '!';
            } else ui = -1;
        }
    }

    cout << dikjstra(si, sj, gi, gj) << endl;

    return 0;
}
