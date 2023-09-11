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

constexpr ll INF = 1e9;

int n;
vector<vector<int>> graph;
vector<int> t;
vector<ll> s, g;
vector<int> medicineNode;

struct State {
    ll strength;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> foundEnemy;
    int medicine;

    void search() {
        while (!foundEnemy.empty()) {
            auto [si, v] = foundEnemy.top();
            if (strength < si) break;
            foundEnemy.pop();
            if (t[v] == 1) strength = min(INF, strength + g[v]);
            for (const int nv : graph[v]) {
                if (t[nv] == 1) {
                    foundEnemy.emplace(s[nv], nv);
                } else {
                    medicine |= 1 << (int)(find(medicineNode.begin(), medicineNode.end(), nv) - medicineNode.begin());
                }
            }
        }
    }
};

int main() {
    cin >> n;
    graph = vector<vector<int>>(n, vector<int>());
    t = vector<int>(n);
    t[0] = 1;
    s = vector<ll>(n);
    g = vector<ll>(n);
    ll maxPower = 0;
    medicineNode = vector<int>();
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p >> t[i] >> s[i] >> g[i];
        if (t[i] == 1) maxPower = max(maxPower, s[i]);
        else medicineNode.push_back(i);
        --p;
        graph[p].push_back(i);
    }
    int m = medicineNode.size();

    vector<State> dp(1 << m);
    dp[0].strength = 1LL;
    dp[0].foundEnemy.emplace(0, 0);
    dp[0].search();

    for (int i = 0; i < (1 << m); ++i) {
        for (int bit = 0; bit < m; ++bit) {
            if (!(i & (1 << bit)) && (dp[i].medicine & (1 << bit))) {
                State newState = dp[i];
                newState.strength = min(INF, newState.strength * g[medicineNode[bit]]);
                newState.foundEnemy.emplace(0, medicineNode[bit]);
                newState.search();
                int ni = i | (1 << bit);
                if (newState.strength > dp[ni].strength) dp[ni] = newState;
            }
        }
    }

    cout << (dp.back().strength >= maxPower ? "Yes" : "No") << endl;

    return 0;
}