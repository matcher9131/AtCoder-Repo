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
    int n, m;
    cin >> n >> m;
    // i >= nは超頂点（m本目の論文そのもの）
    vector<vector<int>> g(n + m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int v;
            cin >> v;
            --v;
            g[n+i].push_back(v);
            g[v].push_back(n+i);
        }
    }

    vector<int> dist(n+m, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int from = que.front();
        que.pop();

        for (const int to : g[from]) {
            if (dist[to] != -1) continue;
            dist[to] = dist[from] + 1;
            que.push(to);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << (dist[i] == -1 ? -1 : dist[i] / 2) << endl;
    }

    return 0;
}