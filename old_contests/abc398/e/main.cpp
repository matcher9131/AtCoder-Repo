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
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> vc(n, -1);
    function<void(int, int)> dfs = [&](int from, int color) -> void {
        vc[from] = color;
        for (const int to : g[from]) {
            if (vc[to] != -1) continue;
            dfs(to, !color);
        }
    };
    dfs(0, 0);

    set<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (find(g[i].begin(), g[i].end(), j) != g[i].end()) continue;
            if (vc[i] != vc[j]) {
                edges.emplace(i, j);
            }
        }
    }

    if (edges.size() % 2) {
        cout << "First" << endl;
        while (true) {
            cout << edges.begin()->first + 1 << " " << edges.begin()->second + 1 << endl;
            edges.erase(edges.begin());
            int i, j;
            cin >> i >> j;
            if (i == -1 && j == -1) {
                return 0;
            }
            --i; --j;
            edges.erase(edges.find({ i, j }));
        }
    } else {
        cout << "Second" << endl;
        while (true) {
            int i, j;
            cin >> i >> j;
            if (i == -1 && j == -1) {
                return 0;
            }
            --i; --j;
            edges.erase(edges.find({ i, j }));
            cout << edges.begin()->first + 1 << " " << edges.begin()->second + 1 << endl;
            edges.erase(edges.begin());
        }
    }

    return 0;
}