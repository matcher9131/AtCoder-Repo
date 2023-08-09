#include <vector>
using namespace std;

extern vector<vector<int>> g;
extern vector<int> visited;


void dfs(int from, vector<int> &visited) {
    visited[from] = 1;
    for (const int to : g[from]) {
        if (visited[to]) continue;
        dfs(to, visited);
    }
}