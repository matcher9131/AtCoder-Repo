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
    int n = 9;
    int m;
    cin >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string p0(n, '0');
    for (ll j = 1; j <= n-1; ++j) {
        int pj;
        cin >> pj;
        --pj;
        p0[pj] = (char)('0' + j);
    }

    unordered_map<string, int> dist;
    dist[p0] = 0;
    queue<string> que;
    que.push(p0);
    while (!que.empty()) {
        string p = que.front();
        que.pop();
        if (p == "123456780") break;
        int blank = p.find('0');
        for (const int to : g[blank]) {
            string np = p;
            swap(np[blank], np[to]);
            if (dist.contains(np)) continue;
            dist[np] = dist[p] + 1;
            que.push(np);
        }
    }

    cout << (dist.contains("123456780") ? dist["123456780"] : -1) << endl;
    return 0;
}