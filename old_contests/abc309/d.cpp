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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

constexpr int INF = 1000000;

void dijkstra(const Graph& g, int from, vector<int>& dist) {
    fill(dist.begin(), dist.end(), INF);
    dist[from] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, from));
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.second;  // 最小距離の頂点
        if (p.first > dist[v]) continue;   // 更新無し
        for (const int node : g[v]) {
            if (dist[v] + 1 < dist[node]) {
                dist[node] = dist[v] + 1;
                que.push(make_pair(dist[node], node));
            }
        }
    }
}

int main() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    Graph g(n1+n2, vector<int>(0));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int z = n1+n2-1;

    vector<bool> seen(n1 + n2);
    vector<int> dist0(n1+n2);
    dijkstra(g, 0, dist0);
    if (dist0[z] != INF) {
        cout << dist0[z] << endl;
        return 0;
    }
    int farthest0 = *max_element(dist0.begin(), dist0.begin() + n1);
    vector<int> distZ(n1+n2);
    dijkstra(g, z, distZ);
    int farthestZ = *max_element(distZ.begin() + n1, distZ.end());
    cout << farthest0 + 1 + farthestZ << endl;
    
    return 0;
}