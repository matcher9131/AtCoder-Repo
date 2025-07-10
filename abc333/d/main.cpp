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

    if ((int)g[0].size() == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> subTreeSize(n);

    function<void(int, int)> dfs = [&](int v, int p) {
        for (const auto c : g[v]) {
            if (c == p) continue;
            dfs(c, v);
        }
        subTreeSize[v] = 1;
        for (const auto c : g[v]) {
            if (c == p) continue;
            subTreeSize[v] += subTreeSize[c];
        }
    };
    dfs(0, -1);

    int ans = n;
    int cm = 0;
    for (const int c : g[0]) {
        cm = max(cm, subTreeSize[c]);
    }
    ans -= cm;

    cout << ans << endl;
    return 0;
}