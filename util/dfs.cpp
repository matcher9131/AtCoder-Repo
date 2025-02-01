#include <vector>
using namespace std;

extern vector<vector<int>> g;
extern vector<int> visited;

void dfs(int from, vector<bool> &visited) {
    visited[from] = true;
    for (const int to : g[from]) {
        if (visited[to]) continue;
        dfs(to, visited);
    }
}