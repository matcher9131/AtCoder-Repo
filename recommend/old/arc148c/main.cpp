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
    int n, nq;
    cin >> n >> nq;
    vector<int> parent(n);
    vector<vector<int>> children(n);
    parent[0] = -1;
    for (int i = 1; i < n; ++i) {
        cin >> parent[i];
        --parent[i];
        children[parent[i]].push_back(i);
    }

    while (nq--) {
        int m;
        cin >> m;
        unordered_set<int> s;
        for (int i = 0; i < m; ++i) {
            int si;
            cin >> si;
            --si;
            s.insert(si);
        }

        int ans = 0;
        for (const int v : s) {
            ans += (int)children[v].size();
            ans += s.contains(parent[v]) ? -1 : 1;
        }
        cout << ans << endl;
    }

    return 0;
}