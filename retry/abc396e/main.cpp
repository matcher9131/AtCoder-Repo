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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        int w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    vector<int> val(n, -1);
    // 連結成分を返す
    auto bfs = [&](int start) -> vector<int> {
        val[start] = 0;
        vector<int> result{ start };
        queue<int> que;
        que.push(start);
        while (!que.empty()) {
            int from = que.front();
            que.pop();
            for (const auto &[to, w] : g[from]) {
                if (val[to] >= 0) {
                    if (val[to] != (val[from] ^ w)) {
                        cout << -1 << endl;
                        exit(0);
                    }
                } else {
                    val[to] = val[from] ^ w;
                    result.push_back(to);
                    que.push(to);
                }
            }
        }
        return result;
    };
    
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (val[i] >= 0) continue;
        auto vertexes = bfs(i);
        for (int bit = 0; bit < 30; ++bit) {
            int numOnes = 0;
            for (const int v : vertexes) {
                if (val[v] & (1 << bit)) ++numOnes;
            }

            if (numOnes < (int)vertexes.size() - numOnes) {
                for (const int v : vertexes) {
                    if (val[v] & (1 << bit)) {
                        ans[v] |= 1 << bit;
                    }
                }
            } else {
                for (const int v : vertexes) {
                    if ((val[v] & (1 << bit)) == 0) {
                        ans[v] |= 1 << bit;
                    }
                }
            }
        }
    }

    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
    return 0;
}