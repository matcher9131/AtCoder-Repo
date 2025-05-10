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
    vector<pair<int, int>> e;
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == 'E') {
                e.emplace_back(i, j);
            }
        }
    }

    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    queue<pair<int, int>> que;
    for (const auto &[ei, ej] : e) {
        que.emplace(ei, ej);
    }
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        for (int dirIndex = 0; dirIndex < 4; ++dirIndex) {
            auto [di, dj] = dir[dirIndex];
            int ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] != '.') continue;
            s[ni][nj] = dirIndex == 0 ? '^' : dirIndex == 1 ? 'v' : dirIndex == 2 ? '<' : '>';
            que.emplace(ni, nj);
        }
    }

    for (int i = 0; i < h; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}