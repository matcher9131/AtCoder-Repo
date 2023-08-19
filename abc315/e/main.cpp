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

void rec(int v, const vector<vector<int>> &g, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    for (const auto nv: g[v]) {
        if (visited[nv]) continue;
        rec(nv, g, visited, order);
    }
    order.push_back(v);
}

void dfs(int v, const vector<vector<int>> &g, vector<int> &visited) {
    visited[v] = 1;
    for (const auto nv: g[v]) {
        if (visited[nv]) continue;
        dfs(nv, g, visited);
    }
}

    
int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<vector<int>> r(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        for (int j = 0; j < c; ++j) {
            int from;
            cin >> from;
            --from;
            g[from].push_back(i);
            r[i].push_back(from);
        }
    }

    vector<int> visited(n);
    vector<int> order;
    for (int v = 0; v < n; ++v) {
        if (visited[v]) continue;
        rec(v, g, visited, order);
    }
    reverse(order.begin(), order.end());

    vector<int> needed(n);
    dfs(0, r, needed);

    vector<int> answer;
    for (const int i : order) {
        if (needed[i] && i != 0) answer.push_back(i);
    }

    cout << answer[0] + 1;
    for (int i = 1; i < answer.size(); ++i) {
        cout << " " << answer[i] + 1;
    }
    cout << endl;
    
    return 0;
}