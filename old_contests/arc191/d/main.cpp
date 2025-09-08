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

constexpr int INF = 1e9;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s;
    --t;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // v, dist
    vector<pair<int, int>> prevFirst(n, make_pair(-1, INF));
    vector<pair<int, int>> prevSecond(n, make_pair(-1, INF));
    // prevFirst[s] = make_pair(s, 0);
    // prevSecond[s] = make_pair(s, 0);
    // v, dist
    queue<pair<int, int>> que;
    que.emplace(s, 0);
    while (!que.empty()) {
        auto current = que.front();
        que.pop();
        for (const int nv : g[current.first]) {
            if (nv == s) continue;
            if (prevFirst[nv].first == -1) {
                // nv未探索なので記録して探索続行
                prevFirst[nv] = current;
                que.emplace(nv, current.second + 1);
            } else if (current.second <= prevFirst[nv].second + 1) {
                // 最短距離+1ならsecondに記録（+1なので同じ辺を行って戻っただけのルートは記録されない）
                // nv探索済なので探索続行はしない
                prevSecond[nv] = current;
            }
        }
    }

    bool same = false;
    bool difOne = false;
    bool tri = false;
    int v = t;
    while (true) {
        if (v == s) break;
        
        auto [pv, d] = prevFirst[v];
        if (prevSecond[v].second == d) {
            same = true;
        } else if (prevSecond[v].second == d + 1) {
            difOne = true;
        }
        if (v != t && g[v].size() >= 3) {
            tri = true;
        }
        
        v = pv;
    }
    
    int distST = prevFirst[t].second + 1;
    int ansShorter = same ? distST * 2
        : difOne ? distST * 2 + 1
        : tri ? distST * 2 + 2
        : -1;

    if (ansShorter >= 0) {
        cout << ansShorter << endl;
        return 0;
    }

    // S,Tの最短パス上で始点か終点にSまたはTを含むものを削除（要するにS,Tの最短パスを一切辿れなくする）
    int pvt = prevFirst[t].first;
    erase(g[pvt], t);
    erase(g[t], pvt);
    v = t;
    while (true) {
        int pv = prevFirst[v].first;
        if (pv == s) {
            erase(g[s], v);
            erase(g[v], s);
            break;
        }
        v = pv;
    }

    int distST2 = ([&]() -> int {
        vector<int> dist(n, INF);
        queue<pair<int, int>> que;
        que.emplace(s, 0);
        while (!que.empty()) {
            auto [v, d] = que.front();
            que.pop();
            for (const int nv : g[v]) {
                if (nv == t) return d + 1;
                if (dist[nv] < d + 1) continue;
                dist[nv] = d + 1;
                que.emplace(nv, d + 1);
            }
        }
        return INF;
    })();
    int ansLonger1 = distST2 >= INF ? INF : distST + distST2;

    auto distNearestTri = [&](int start) -> int {
        vector<bool> visited(n);
        // v, dist
        queue<pair<int, int>> que;
        que.emplace(start, 0);
        while (!que.empty()) {
            auto [v, d] = que.front();
            que.pop();
            if (g[v].size() >= 3) return d;
            if (visited[v]) continue;
            visited[v] = true;
            for (const int nv : g[v]) {
                que.emplace(nv, d + 1);
            }
        }
        return INF;
    };

    int stot = distNearestTri(s);
    int ttot = distNearestTri(t);
    
    int ansLonger2 = (stot >= INF && ttot >= INF) ? INF : 2 * distST + 4 * (min(stot, ttot) + 1);

    int ansLonger = min(ansLonger1, ansLonger2);

    cout << (ansLonger >= INF ? -1 : ansLonger) << endl;

    return 0;
}