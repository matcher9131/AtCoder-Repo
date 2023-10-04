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

    vector<int> color(n);
    int numBlack = 0;
    function<void(int, int)> dfs = [&](int from, int c) {
        color[from] = c;
        if (c == 1) ++numBlack;
        for (const int to : g[from]) {
            if (color[to] != 0) continue;
            dfs(to, -c);
        }
    };
    dfs(0, 1);

    vector<int> ans;
    ans.reserve(n);
    int majorColor = numBlack >= n / 2 ? 1 : -1;
    for (int i = 0; i < n; ++i) {
        if (color[i] == majorColor) ans.push_back(i);
    }

    cout << ans[0] + 1;
    for (int i = 1; i < n / 2; ++i) {
        cout << " " << ans[i] + 1;
    }
    cout << endl;

    return 0;
}