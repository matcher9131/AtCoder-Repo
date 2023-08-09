#include <vector>
#include <queue>
using namespace std;

extern vector<vector<pair<int, int>>> g;


void dijkstra(int root, vector<int>& d) {
    d[root] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, root);
    while (!que.empty()) {
        auto [dist, v] = que.top();
        que.pop();
        if (dist > d[v]) continue;
        for (const auto [nv, cost] : g[v]) {
            if (d[v] + cost < d[nv]) {
                d[nv] = d[v] + cost;
                que.emplace(d[nv], nv);
            }
        }
    }
}
