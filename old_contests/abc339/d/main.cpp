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
    int n;
    cin >> n;
    vector<string> s(n);
    vector<pair<int, int>> players;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        auto j = s[i].find('P');
        if (j != string::npos) {
            players.emplace_back(i, j);
            auto j2 = s[i].find('P', j+1);
            if (j2 != string::npos) {
                players.emplace_back(i, j2);
            }
        }
    }

    auto [si, sj] = players[0];
    auto [gi, gj] = players[1];
    vector<pair<int, int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };    

    auto move = [&](int i, int j, int di, int dj) -> pair<int, int> {
        int ni = i + di;
        int nj = j + dj;
        if (ni < 0 || ni >= n || nj < 0 || nj >= n || s[ni][nj] == '#') {
            return { i, j };
        } else {
            return { ni, nj };
        }
    };

    vector<vector<vector<vector<ll>>>> dist(n, vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(n, INF))));
    dist[si][sj][gi][gj] = 0;
    queue<tuple<int, int, int, int>> que;
    que.emplace(si, sj, gi, gj);
    while (!que.empty()) {
        auto [i1, j1, i2, j2] = que.front();
        if (i1 == i2 && j1 == j2) {
            cout << dist[i1][j1][i2][j2] << endl;
            return 0;
        }
        que.pop();
        for (const auto &[di, dj] : dir) {
            auto [ni1, nj1] = move(i1, j1, di, dj);
            auto [ni2, nj2] = move(i2, j2, di, dj);
            if (dist[ni1][nj1][ni2][nj2] == INF) {
                dist[ni1][nj1][ni2][nj2] = dist[i1][j1][i2][j2] + 1;
                que.emplace(ni1, nj1, ni2, nj2);
            }
        }
    }

    cout << -1 << endl;

    return 0;
}