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
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    set<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dist[i][j] > 1 && dist[i][j] % 2 == 1) edges.emplace(i, j);
        }
    }

    if ((int)edges.size() % 2 == 1) {
        cout << "First" << endl;
        while (true) {
            cout << edges.begin()->first + 1 << " " << edges.begin()->second + 1 << endl;
            edges.erase(edges.begin());
            int i, j;
            cin >> i >> j;
            if (i == -1 && j == -1) {
                return 0;
            }
            if (i > j) swap(i, j);
            auto it = edges.find({ i, j });
            edges.erase(it);
        }
    } else {
        cout << "Second" << endl;
        while (true) {
            int i, j;
            cin >> i >> j;
            if (i == -1 && j == -1) {
                return 0;
            }
            if (i > j) swap(i, j);
            auto it = edges.find({ i, j });
            edges.erase(it);
            cout << edges.begin()->first + 1 << " " << edges.begin()->second + 1 << endl;
            edges.erase(edges.begin());
        }
    }

    return 0;
}