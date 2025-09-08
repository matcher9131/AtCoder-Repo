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

constexpr int INF = 1e7;

int main() {
    int n, m;
    cin >> n >> m;
    atcoder::dsu d(n);
    vector<int> val(n, INF);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        if (!d.same(a, b)) {
            if (val[b] == INF) val[b] = 0;
            int dif = (val[b] + c) - val[a];
            for (const auto &group : d.groups()) {
                if (find(group.begin(), group.end(), a) != group.end()) {
                    for (const int v : group) {
                        val[v] += dif;
                    }
                }
            }
            d.merge(a, b);
        }
    }

    // val, index
    vector<vector<pair<int, int>>> groups;
    for (const auto &group : d.groups()) {
        vector<pair<int, int>> g;
        for (const int v : group) {
            g.emplace_back(val[v], v);
        }
        sort(g.begin(), g.end());
        for (int i = (int)g.size() - 1; i >= 0; --i) {
            g[i].first -= g[0].first;
        }
        groups.push_back(g);
    }
    // グループのサイズ降順でソート
    sort(groups.begin(), groups.end(), [](vector<pair<int, int>> &x, vector<pair<int, int>> &y) {
        return x.size() > y.size();
    });
    // 孤立点が2個以上あるときは除外する
    if (count_if(groups.begin(), groups.end(), [](vector<pair<int, int>> &x) {
        return (int)x.size() == 1;
    }) >= 2) {
        for (int i = (int)groups.size() - 1; i >= 0; --i) {
            if ((int)groups[i].size() > 1) break;
            groups.erase(groups.begin() + i);
        }
    }

    // i位が誰か
    vector<int> revRank(n, -1);
    vector<set<int>> possibleRanks(n);
    function<void(int)> dfs = [&](int gi) {
        if (gi == (int)groups.size()) {
            for (int rank = 0; rank < n; ++rank) {
                if (revRank[rank] > -1) {
                    possibleRanks[revRank[rank]].insert(rank);
                }
            }
        } else {
            for (int br = 0; br < n; ++br) {
                if (!all_of(groups[gi].begin(), groups[gi].end(), [&](pair<int, int> p) {
                    return br + p.first < n && revRank[br + p.first] == -1;
                })) continue;
                for (const auto &[val, i] : groups[gi]) {
                    revRank[br + val] = i;
                }
    
                dfs(gi + 1);

                for (const auto &[val, i] : groups[gi]) {
                    revRank[br + val] = -1;
                }
            }
        }
    };
    dfs(0);

    for (int i = 0; i < n; ++i) {
        cout << ((int)possibleRanks[i].size() == 1 ? (*possibleRanks[i].begin() + 1) : -1) << " \n"[i == n - 1];
    }

    return 0;
}