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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, int>> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a[i] = { ai, i };
    }
    for (int j = 0; j < m; ++j) {
        ll bj;
        cin >> bj;
        b[j] = { bj, j };
    }
    set<pair<int, int>> p;
    for (int i = 0; i < k; ++i) {
        int ci, dj;
        cin >> ci >> dj;
        --ci;
        --dj;
        p.emplace(ci, dj);
    }
    sort(a.begin(), a.end(), greater<pair<ll, int>>());
    sort(b.begin(), b.end(), greater<pair<ll, int>>());
    
    ll ans = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> que;
    que.emplace(a[0].first + b[0].first, 0, 0);
    set<pair<int, int>> visited;
    while (!que.empty()) {
        auto [v, i, j] = que.top();
        que.pop();
        visited.emplace(i, j);
        if (p.contains({a[i].second, b[j].second})) {
            if (i < n && !visited.contains({i+1, j})) que.emplace(a[i+1].first + b[j].first, i+1, j);
            if (j < m && !visited.contains({i, j+1})) que.emplace(a[i].first + b[j+1].first, i, j+1);
        } else {
            ans = max(ans, v);
        }
    }

    cout << ans << endl;

    return 0;
}