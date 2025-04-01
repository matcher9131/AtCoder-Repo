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
    for (int i = 1; i < n; ++i) {
        int pi;
        cin >> pi;
        --pi;
        g[pi].push_back(i);
    }

    vector<int> depth(n), tin(n), tout(n);
    function<void(int,int,int&)> dfs = [&](int from, int d, int& t) -> void {
        depth[from] = d;
        tin[from] = t++;
        for (const int to : g[from]) {
            dfs(to, d + 1, t);
        }
        tout[from] = t++;
    };
    int t = 0;
    dfs(0, 0, t);

    unordered_map<int, vector<int>> depthTinMap;
    for (int i = 0; i < n; ++i) {
        depthTinMap[depth[i]].push_back(tin[i]);
    }
    for (auto& [_, v] : depthTinMap) {
        sort(v.begin(), v.end());
    }

    int q;
    cin >> q;
    while (q--) {
        int ui, di;
        cin >> ui >> di;
        --ui;
        int ans = lower_bound(depthTinMap[di].begin(), depthTinMap[di].end(), tout[ui]) - lower_bound(depthTinMap[di].begin(), depthTinMap[di].end(), tin[ui]);
        cout << ans << endl;
    }

    return 0;
}