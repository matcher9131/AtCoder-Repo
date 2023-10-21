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
    ll a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<ll>> g(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    dist[0][0] = 0;
    dist[0][1] = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> que;
    que.emplace(0, 0, 0);
    while (!que.empty()) {
        auto [d, v, method] = que.top();
        que.pop();
        if (method == 0) {
            if (d <= dist[v][0]) {
                for (int i = 0; i < n; ++i) {
                    if (i == v) continue;
                    ll newDistCar = dist[v][0] + g[v][i] * a;
                    if (newDistCar < dist[i][0]) {
                        dist[i][0] = newDistCar;
                        que.emplace(newDistCar, i, 0);
                    }
                    ll newDistTrain = min(dist[v][0], dist[v][1]) + g[v][i] * b + c;
                    if (newDistTrain < dist[i][1]) {
                        dist[i][1] = newDistTrain;
                        que.emplace(newDistTrain, i, 1);
                    }
                }
            }
        } else {
            if (d <= dist[v][1]) {
                for (int i = 0; i < n; ++i) {
                    if (i == v) continue;
                    ll newDistTrain = min(dist[v][0], dist[v][1]) + g[v][i] * b + c;
                    if (newDistTrain < dist[i][1]) {
                        dist[i][1] = newDistTrain;
                        que.emplace(newDistTrain, i, 1);
                    }
                }
            }
        }
    }

    cout << min(dist[n - 1][0], dist[n - 1][1]) << endl;

    return 0;
}