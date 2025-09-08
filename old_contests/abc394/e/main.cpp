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
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    queue<pair<int, int>> que;
    for (int i = 0; i < n; ++i) {
        que.push({ i, i });
        dist[i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || s[i][j] == '-') continue;
            que.push({ i, j });
            dist[i][j] = 1;
        }
    }
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        for (int w = 0; w < n; ++w) {
            for (int z = 0; z < n; ++z) {
                if (dist[w][z] < INF) continue;
                if (s[w][x] != '-' && s[y][z] != '-' && s[w][x] == s[y][z]) {
                    dist[w][z] = dist[x][y] + 2;
                    que.push({ w, z });
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (dist[i][j] >= INF ? -1 : dist[i][j]) << " \n"[j == n - 1];
        }
    }
    

    return 0;
}