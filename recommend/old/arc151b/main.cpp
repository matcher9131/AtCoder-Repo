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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }

    vector<bool> visited(n);
    function<void(int)> dfs = [&](int v) -> void {
        visited[v] = true;
        for (const int& nv : g[v]) {
            if (visited[nv]) continue;
            dfs(nv);
        }
    };
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
            ++count;
        }
    }

    mint mm = m;
    mint ans = (mm.pow(n) - mm.pow(count)) / 2;
    cout << ans.val() << endl;

    return 0;
}