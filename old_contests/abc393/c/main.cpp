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
    int ans = 0;
    unordered_map<int, unordered_set<int>> edge;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (u == v || edge[u].contains(v) || edge[v].contains(u)) {
            ++ans;
        } else {
            edge[u].insert(v);
        }
    }

    cout << ans << endl;

    return 0;
}