#include <vector>
#include <functional>
using namespace std;
extern int n;
extern vector<vector<int>> g;


vector<bool> visited(n);
function<void(int)> dfs = [&](int from) -> void {
    visited[from] = true;
    for (const int to : g[from]) {
        if (visited[to]) continue;
        dfs(from);
    }
};
