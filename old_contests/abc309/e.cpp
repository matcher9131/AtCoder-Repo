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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

void addTarget(const Graph& g, unordered_set<int>& targets, int parent, int gens) {
    targets.insert(parent);
    if (gens > 0) {
        for (const int child : g[parent]) {
            addTarget(g, targets, child, gens - 1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, vector<int>(0));
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }
    vector<pair<int, int>> ins(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        --x;
        ins[i] = make_pair(x, y);
    }
    
    unordered_set<int> target;
    for (const auto& p : ins)
    {
        addTarget(g, target, p.first, p.second);
    }
    
    //
    // for (int i = 0; i < n; ++i) {
    //     if (target.find(i) != target.end()) {
    //         cout << i << "is target." << endl;
    //     }
    // }
    //
    cout << target.size() << endl;
    
    return 0;
}