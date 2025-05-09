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
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<int> depth(n, -1);
    vector<ll> subTreeValue(n);

    function<void(int,int,int)> dfs = [&](int from, int parent, int currentDepth) -> void {
        depth[from] = currentDepth;
        for (const int to : g[from]) {
            if (depth[to] >= 0) continue;
            dfs(to, from, currentDepth + 1);
        }
        subTreeValue[from] = c[from];
        for (const int to : g[from]) {
            if (to == parent) continue;
            subTreeValue[from] += subTreeValue[to];
        }
    };
    dfs(0, -1, 0);

    vector<ll> fx(n);
    for (int i = 0; i < n; ++i) {
        fx[0] += c[i] * depth[i];
    }

    function<void(int,int)> dfs2 = [&](int from, int parent) -> void {
        if (parent != -1) {
            fx[from] = fx[parent] - subTreeValue[from] + (subTreeValue[0] - subTreeValue[from]);
        }
        for (const int to : g[from]) {
            if (to == parent) continue;
            dfs2(to, from);
        }
    };
    dfs2(0, -1);

    cout << *min_element(fx.begin(), fx.end()) << endl;

    return 0;
}