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
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> visited(n);

    function<void(int,vector<int>&)> dfs = [&](int from, vector<int> &connection) -> void {
        visited[from] = true;
        connection.push_back(from);
        for (const int to : g[from]) {
            if (visited[to]) continue;
            dfs(to, connection);
        }
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        vector<int> connection;
        dfs(i, connection);

        int numEdges = 0;
        for (const int v : connection) {
            numEdges += (int)g[v].size();
        }
        numEdges /= 2;
        ans += numEdges - ((int)connection.size() - 1);
    }

    cout << ans << endl;
    return 0;
}