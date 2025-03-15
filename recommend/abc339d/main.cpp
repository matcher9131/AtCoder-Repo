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

constexpr int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    int s1i = -1, s1j = -1, s2i = -1, s2j = -1;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        auto pos = s[i].find('P');
        if (pos != string::npos) {
            if (s1i == -1) {
                s1i = i;
                s1j = (int)pos;
                auto pos2 = s[i].find('P', pos + 1);
                if (pos2 != string::npos) {
                    s2i = i;
                    s2j = (int)pos2;
                }
            } else {
                s2i = i;
                s2j = (int)pos;
            }
        }
    }

    vector<pair<int, int>> next = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    auto isMovable = [&](int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < n && s[i][j] != '#';
    };

    vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, INF))));
    queue<tuple<int, int, int, int>> que;
    dist[s1i][s1j][s2i][s2j] = 0;
    que.emplace(s1i, s1j, s2i, s2j);

    while (!que.empty()) {
        auto [i1, j1, i2, j2] = que.front();
        que.pop();

        if (i1 == i2 && j1 == j2) {
            cout << dist[i1][j1][i2][j2] << endl;
            return 0;
        }

        for (const auto& [di, dj] : next) {
            auto [ni1, nj1] = isMovable(i1 + di, j1 + dj) ? make_pair(i1 + di, j1 + dj) : make_pair(i1, j1);
            auto [ni2, nj2] = isMovable(i2 + di, j2 + dj) ? make_pair(i2 + di, j2 + dj) : make_pair(i2, j2);
            if (dist[ni1][nj1][ni2][nj2] != INF) continue;

            dist[ni1][nj1][ni2][nj2] = dist[i1][j1][i2][j2] + 1;
            que.emplace(ni1, nj1, ni2, nj2);
        }
    }

    cout << -1 << endl;

    return 0;
}