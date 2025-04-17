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
#include <atcoder/scc>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    atcoder::scc_graph g(n);
    vector<vector<int>> g2(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g.add_edge(a, b);
        g2[a].push_back(b);
    }

    vector<vector<int>> groups = g.scc();
    vector<int> revGroup(n);
    for (int i = 0; i < (int)groups.size(); ++i) {
        for (const int v : groups[i]) {
            revGroup[v] = i;
        }
    }
    
    vector<bool> dp(groups.size());
    for (int i = (int)groups.size() - 1; i >= 0; --i) {
        if ((int)groups[i].size() > 1) {
            dp[i] = true;
        } else {
            for (const int to : g2[groups[i][0]]) {
                dp[i] = dp[i] || dp[revGroup[to]];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (int)groups.size(); ++i) {
        if (dp[i]) ans += (int)groups[i].size();
    }

    cout << ans << endl;
    return 0;
}