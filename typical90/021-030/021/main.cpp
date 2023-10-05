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
    vector<vector<int>> g(n), gr(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    
    vector<bool> visited(n);
    vector<int> post;
    function<void(int)> dfs = [&](int from) {
        visited[from] = true;
        for (const int to : g[from]) {
            if (visited[to]) continue;
            dfs(to);
        }
        post.push_back(from);
    };
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        dfs(i);
    }

    ll ans = 0;
    vector<bool> visited2(n);
    function<void(int, ll&)> dfsr = [&](int from, ll &size) {
        visited2[from] = true;
        ++size;
        for (const int to : gr[from]) {
            if (visited2[to]) continue;
            dfsr(to, size);
        }
    };
    for (auto it = post.rbegin(); it != post.rend(); ++it) {
        if (visited2[*it]) continue;
        ll c = 0;
        dfsr(*it, c);
        if (c > 1) ans += c * (c - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}