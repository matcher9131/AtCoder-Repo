#include <vector>
#include <queue>
using namespace std;
using ll = long long;

extern int n;
extern vector<vector<pair<int, ll>>> g;
extern int INF;

void dijkstra(int root) {
    vector<ll> dist(n, INF);
    dist[root] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, root);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (const auto& [nv, cost] : g[v]) {
            if (dist[v] + cost < dist[nv]) {
                dist[nv] = dist[v] + cost;
                que.emplace(dist[nv], nv);
            }
        }
    }
}
