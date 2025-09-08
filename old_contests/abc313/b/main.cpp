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
using namespace std;
using ll = long long;


int n, m;
vector<vector<int>> g;
 
void dfs(int from, vector<int>& visited) {
    visited[from] = 1;
    for (const auto to : g[from]) {
        if (visited[to]) continue;
        dfs(to, visited);
    }
}
 
bool allVisited(const vector<int>& visited) {
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) return false;
    }
    return true;
}
 
int main() {
    cin >> n >> m;
    g = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
    }
 
    for (int i = 0; i < n; ++i) {
        vector<int> visited(n);
        dfs(i, visited);
        if (allVisited(visited)) {
            cout << (i + 1) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
 
    return 0;
}