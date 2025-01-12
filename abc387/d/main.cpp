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

constexpr int INF = 1e6;


int main() {
    int h, w;
    cin >> h >> w;
    int si, sj, gi, gj;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
        int j;
        j = s[i].find('S');
        if (j != string::npos) {
            si = i;
            sj = j;
        }
        j = s[i].find('G');
        if (j != string::npos) {
            gi = i;
            gj = j;
        }
    }
    s[gi][gj] = '.';

    auto dijkstra = [&](bool initialHorizontal) {
        vector<vector<int>> d(h, vector<int>(w, INF));
        d[si][sj] = 0;
        vector<vector<bool>> v(h, vector<bool>(w));
        // cost, i, j, horizontal
        queue<tuple<int, int, int, bool>> q;
        q.emplace(0, si, sj, initialHorizontal);
        while (!q.empty()) {
            auto [c, i, j, horizontal] = q.front();
            if (i == gi && j == gj) return c;
            q.pop();
            if (v[i][j]) continue;
            v[i][j] = true;
            if (horizontal) {
                if (j > 0 && s[i][j-1] == '.' && d[i][j-1] > d[i][j] + 1) {
                    d[i][j-1] = d[i][j] + 1;
                    q.emplace(d[i][j-1], i, j-1, !horizontal);
                }
                if (j < w - 1 && s[i][j+1] == '.' && d[i][j+1] > d[i][j] + 1) {
                    d[i][j+1] = d[i][j] + 1;
                    q.emplace(d[i][j+1], i, j+1, !horizontal);
                }
            } else {
                if (i > 0 && s[i-1][j] == '.' && d[i-1][j] > d[i][j] + 1) {
                    d[i-1][j] = d[i][j] + 1;
                    q.emplace(d[i-1][j], i-1, j, !horizontal);
                }
                if (i < h - 1 && s[i+1][j] == '.' && d[i+1][j] > d[i][j] + 1) {
                    d[i+1][j] = d[i][j] + 1;
                    q.emplace(d[i+1][j], i+1, j, !horizontal);
                }
            }
        }
        return INF;
    };

    int ans = min(dijkstra(true), dijkstra(false));

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}