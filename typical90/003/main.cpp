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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    function<void(int, vector<int>&, int)> dfs = [&](int from, vector<int> &depth, int cd) {
        depth[from] = cd;
        for (const int to : g[from]) {
            if (depth[to] >= 0) continue;
            dfs(to, depth, cd + 1);
        }
    };

    vector<int> depth(n, -1);
    dfs(0, depth, 0);
    int deepest = max_element(depth.begin(), depth.end()) - depth.begin();
    vector<int> depth2(n, -1);
    dfs(deepest, depth2, 0);
    cout << *max_element(depth2.begin(), depth2.end()) + 1 << endl;

    return 0;
}