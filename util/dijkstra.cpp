#include <vector>
#include <queue>
using namespace std;

extern vector<vector<pair<int, int>>> g;
extern int INF;

void dijkstra(int root, vector<int>& dist) {
    fill(dist.begin(), dist.end(), INF);
    dist[root] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, root);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (const auto [nv, cost] : g[v]) {
            if (dist[v] + cost < dist[nv]) {
                dist[nv] = dist[v] + cost;
                que.emplace(dist[nv], nv);
            }
        }
    }
}
