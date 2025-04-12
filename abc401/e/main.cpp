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
#include <atcoder/dsu>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    // to, from
    vector<pair<int, int>> edge(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        edge[i] = { b, a };
    }
    sort(edge.begin(), edge.end());

    atcoder::dsu d(n);
    set<int> next(g[0].begin(), g[0].end());
    cout << next.size() << endl;

    for (int i = 1; i < n; ++i) {
        auto itl = lower_bound(edge.begin(), edge.end(), make_pair(i, 0));
        auto itr = lower_bound(edge.begin(), edge.end(), make_pair(i + 1, 0));
        for (auto it = itl; it != itr; ++it) {
            auto [to, from] = *it;
            d.merge(from, to);
        }
        
        next.erase(i);
        for (const int to : g[i]) {
            if (to > i) {
                next.insert(to);
            }
        }

        if (d.size(0) == i + 1) {
            cout << next.size() << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}