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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    // number, dist
    vector<pair<int, int>> cycleInfo(n, make_pair(-1, -1));
    vector<int> cycleNumVertexes;

    vector<bool> pre(n), post(n);
    stack<int> history;
    function<int(int)> dfs = [&](int from) -> int {
        pre[from] = true;
        history.push(from);
        int to = a[from];
        if (cycleInfo[to] != make_pair(-1, -1)) {
            return -1;
        } else if (!post[to]) {
            if (pre[to]) return to;
            return dfs(to);
        }
        history.pop();
        post[from] = true;
        return -1;
    };

    int ccn = 0;
    for (int i = 0; i < n; ++i) {
        if (pre[i]) continue;
        int cv = dfs(i);
        if (cv == -1) {
            // 途中で付近のサイクル検出済みの探索済み頂点にぶつかった
            while (!history.empty()) {
                int v = history.top();
                history.pop();
                auto [cn, d] = cycleInfo[a[v]];
                cycleInfo[v] = { cn, d + 1 };
            }
        } else {
            // 新たにサイクルを検出した
            int dist = -1;
            int numVertexes = 0;
            while (!history.empty()) {
                int v = history.top();
                history.pop();
                if (dist == -1) {
                    ++numVertexes;
                    cycleInfo[v] = { ccn, 0 };
                } else {
                    cycleInfo[v] = { ccn, ++dist };
                }
                if (v == cv) dist = 0;
            }
            cycleNumVertexes.push_back(numVertexes);
            ++ccn;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto [cn, d] = cycleInfo[i];
        ans += cycleNumVertexes[cn] + d;
    }

    cout << ans << endl;
    return 0;
}