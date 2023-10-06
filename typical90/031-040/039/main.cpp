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

    vector<ll> subtreeSize(n, 1);
    vector<ll> ans(n);
    function<void(int, int, ll)> dfs = [&](int from, int parent, ll d) {
        ans[0] += d;
        for (const int to : g[from]) {
            if (to == parent) continue;
            dfs(to, from, d + 1);
            subtreeSize[from] += subtreeSize[to];
        }
    };
    dfs(0, -1, 0);

    function<void(int, int)> dfsAnswer = [&](int from, int parent) {
        for (const int to : g[from]) {
            if (to == parent) continue;
            ans[to] = ans[from] + n - 2 * subtreeSize[to];
            dfsAnswer(to, from);
        }
    };
    dfsAnswer(0, -1);

    cout << accumulate(ans.begin(), ans.end(), 0LL) / 2 << endl;

    return 0;
}