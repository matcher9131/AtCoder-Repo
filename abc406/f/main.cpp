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
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;

using S = ll;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edge(n-1);
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        edge[i] = { a, b };
    }

    vector<int> pre(n), post(n);
    vector<ll> w(n, 1);
    function<void(int,int,int&)> dfs = [&](int v, int parent, int& time) -> void {
        pre[v] = time++;
        for (const int child : g[v]) {
            if (child == parent) continue;
            dfs(child, v, time);
            
        }
        post[v] = time++;
        for (const int child : g[v]) {
            if (child == parent) continue;
            w[v] += w[child];
        }
    };
    int time = 0;
    dfs(0, -1, time);
    atcoder::fenwick_tree<ll> fw(time);
    for (int i = 0; i < n; ++i) {
        fw.add(post[i], 1);
    }

    int nq;
    cin >> nq;
    vector<tuple<int, int, int>> q(nq);
    for (int qi = 0; qi < nq; ++qi) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, wv;
            cin >> x >> wv;
            --x;
            fw.add(post[x], wv);
        } else {
            int y;
            cin >> y;
            --y;
            auto [a, b] = edge[y];
            int child = pre[a] < pre[b] ? b : a;
            ll wc = fw.sum(pre[child], post[child] + 1);
            ll ws = fw.sum(0, time);
            ll wp = ws - wc;
            cout << abs(wc- wp) << endl;
        }
    }


    return 0;
}