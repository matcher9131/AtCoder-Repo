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
    int n;
    cin >> n;
    vector<tuple<ll, int, int>> edges(n-1);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        edges[i] = { w, u, v };
    }
    sort(edges.begin(), edges.end());

    ll ans = 0;
    atcoder::dsu g(n);
    for (const auto& [w, u, v] : edges) {
        int c1 = g.size(u);
        int c2 = g.size(v);
        g.merge(u, v);
        ans += w * c1 * c2;
    }

    cout << ans << endl;
    return 0;
}