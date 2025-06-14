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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        int w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
    }

    vector<vector<bool>> visited(n, vector<bool>(1024));
    function<void(int, int)> dfs = [&](int from, int val) {
        visited[from][val] = true;
        for (const auto &[to, w] : g[from]) {
            int newVal = val ^ w;
            if (visited[to][newVal]) continue;
            dfs(to, newVal);
        }
    };
    dfs(0, 0);

    for (int i = 0; i < 1024; ++i) {
        if (visited[n-1][i]) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}