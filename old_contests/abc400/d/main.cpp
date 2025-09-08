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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a;
    --b;
    --c;
    --d;

    auto within = [&](int i, int j) -> bool {
        return i >= 0 && i < h && j >= 0 && j < w;
    };

    vector<pair<int, int>> dir{ {1,0}, {-1,0}, {0,1}, {0,-1} };

    vector<vector<int>> dist(h, vector<int>(w, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
    dist[a][b] = 0;
    que.emplace(0, a, b);

    while (!que.empty()) {
        auto [_d, i, j] = que.top();
        que.pop();
        if (i == c && j == d) {
            cout << dist[i][j] << endl;
            return 0;
        }

        if (_d > dist[i][j]) continue;

        for (const auto& [di, dj] : dir) {
            int ni = i + di, nj = j + dj;
            if (!within(ni, nj)) continue;
            if (s[ni][nj] == '#') {
                for (int k = 1; k <= 2; ++k) {
                    int ni2 = i + k * di, nj2 = j + k * dj;
                    if (!within(ni2, nj2)) continue;
                    if (dist[i][j] + 1 < dist[ni2][nj2]) {
                        dist[ni2][nj2] = dist[i][j] + 1;
                        que.emplace(dist[ni2][nj2], ni2, nj2);
                    }
                }
            } else {
                if (dist[i][j] < dist[ni][nj]) {
                    dist[ni][nj] = dist[i][j];
                    que.emplace(dist[ni][nj], ni, nj);
                }
            }
        }
    }

    return 0;
}