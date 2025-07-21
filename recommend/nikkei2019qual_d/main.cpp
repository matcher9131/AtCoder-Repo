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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ll> inDeg(n);
    for (ll i = 0; i < n-1+m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        ++inDeg[b];
    }

    queue<ll> que;
    vector<ll> parent(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (inDeg[i] == 0) {
            que.push(i);
            break;
        }
    }
    
    while (!que.empty()) {
        ll from = que.front();
        que.pop();
        for (const ll to : g[from]) {
            --inDeg[to];
            if (inDeg[to] == 0) {
                parent[to] = from;
                que.push(to);
            }
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << parent[i] + 1 << endl;
    }
    return 0;
}