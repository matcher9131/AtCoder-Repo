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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + m);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        for (int j = 0; j < ai; ++j) {
            int sij;
            cin >> sij;
            --sij;
            g[i].push_back(n + sij);
            g[n + sij].push_back(i);
        }
    }

    vector<int> dist(n+m, INF);
    dist[n] = 0;
    queue<int> que;
    que.push(n);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (const int nv : g[v]) {
            if (dist[nv] < INF) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cout << (dist[n+m-1] == INF ? -1 : (dist[n+m-1] - 2) / 2) << endl;

    return 0;
}