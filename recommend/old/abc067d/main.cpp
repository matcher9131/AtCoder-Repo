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
#include <atcoder/segtree>
using namespace std;
using ll = long long;

using S = bool;
S op(S a, S b) {
    return a || b;
}
S e() {
    return false;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> depth(n, -1);
    vector<int> pre(n, -1), post(n, -1);
    function<void(int, int, int&)> dfs = [&](int from, int d, int &t) -> void {
        depth[from] = d;
        pre[from] = t++;
        for (const int to : g[from]) {
            if (depth[to] != -1) continue;
            dfs(to, d+1, t);
        }
        post[from] = t++;
    };
    int t = 0;
    dfs(0, 0, t);

    vector<bool> selected(n);
    atcoder::segtree<S, op, e> seg(2 * n);
    seg.set(post[n-1], true);
    int cb = 0, cw = n-1;
    while (true) {
        bool done = true;
        // Fennec: 白が含まれる子を選ぶ
        for (const int child : g[cb]) {
            if (depth[child] <= depth[cb]) continue;
            if (selected[child]) continue;
            if (seg.prod(pre[child], post[child])) {
                selected[child] = true;
                cb = child;
                done = false;
                break;
            }
        }
        // Snuke: 親を選ぶ
        for (const int parent : g[cw]) {
            if (depth[parent] >= depth[cw]) continue;
            if (selected[parent]) continue;
            selected[parent] = true;
            seg.set(post[parent], true);
            cw = parent;
            done = false;
        }

        if (done) break;
    }

    int numWhite = (post[cw] - pre[cw] + 1) / 2;
    int numBlack = n - numWhite;

    cout << (numBlack > numWhite ? "Fennec" : "Snuke") << endl;  

    return 0;
}