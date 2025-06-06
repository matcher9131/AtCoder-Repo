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

constexpr ll INF = 1e18;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n-1), b(n-1);
    vector<int> x(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> a[i] >> b[i] >> x[i];
        --x[i];
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (v == n-1) continue;
        if (d > dist[v]) continue;
        {
            int nv = v + 1;
            ll newCost = dist[v] + a[v];
            if (newCost < dist[nv]) {
                dist[nv] = newCost;
                que.emplace(newCost, nv);
            }
        }
        {
            int nv = x[v];
            ll newCost = dist[v] + b[v];
            if (newCost < dist[nv]) {
                dist[nv] = newCost;
                que.emplace(newCost, nv);
            }
        }
    }

    cout << dist[n-1] << endl;

    return 0;
}