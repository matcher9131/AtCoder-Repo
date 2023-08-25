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
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> g;
vector<int> visited;

void dfs(int from) {
    visited[from] = 1;
    for (const int to : g[from]) {
        if (visited[to]) continue;
        dfs(to);
    }
}

int main() {
    cin >> n >> m;
    g = vector<vector<int>>(n, vector<int>());
    visited = vector<int>(n);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        dfs(i);
        ++answer;
    }

    cout << answer << endl;

    return 0;
}