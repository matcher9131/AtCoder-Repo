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

    vector<vector<int>> dist(h, vector<int>(w, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
    dist[0][0] = 0;
    que.emplace(0, 0, 0);
    
    auto within = [&](int i, int j) {
        return i >= 0 && i < h && j >= 0 && j < w;
    };
    
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!que.empty()) {
        auto [d, i, j] = que.top();
        que.pop();
        if (i == h-1 && j == w-1) {
            cout << dist[i][j] << endl;
            return 0;
        }

        if (d > dist[i][j]) continue;

        for (const auto& [di, dj] : dir) {
            int ni = i + di, nj = j + dj;
            if (!within(ni, nj)) continue;
            if (s[ni][nj] == '#') {
                if (di != 0) {
                    for (int di2 = 1; di2 <= 2; ++di2) {
                        for (int dj2 = -1; dj2 <= 1; ++dj2) {
                            int ni2 = i + di2 * (di == 1 ? 1 : -1), nj2 = j + dj2;
                            if (within(ni2, nj2)) {
                                if (dist[i][j] + 1 < dist[ni2][nj2]) {
                                    dist[ni2][nj2] = dist[i][j] + 1;
                                    que.emplace(dist[ni2][nj2], ni2, nj2);
                                }
                            }
                        }
                    }
                } else {
                    for (int dj2 = 1; dj2 <= 2; ++dj2) {
                        for (int di2 = -1; di2 <= 1; ++di2) {
                            int ni2 = i + di2, nj2 = j + dj2 * (dj == 1 ? 1 : -1);
                            if (within(ni2, nj2)) {
                                if (dist[i][j] + 1 < dist[ni2][nj2]) {
                                    dist[ni2][nj2] = dist[i][j] + 1;
                                    que.emplace(dist[ni2][nj2], ni2, nj2);
                                }
                            }
                        }
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