#include <vector>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> visited;
void dfs(int from) {
    visited[from] = 1;
    for (const int to : g[from]) {
        if (visited[to]) continue;
        dfs(to);
    }
}