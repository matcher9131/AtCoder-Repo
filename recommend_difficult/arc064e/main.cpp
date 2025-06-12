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

constexpr double INF = 1e18;

double getDist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    vector<double> x(n+2), y(n+2), r(n+2);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }
    x[0] = xs, y[0] = ys, r[0] = 0;
    x[n+1] = xt, y[n+1] = yt, r[n+1] = 0;

    vector<vector<double>> g(n+2, vector<double>(n+2));
    for (int i = 0; i < n+2; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j) {
                g[i][j] = INF;
            } else {
                double between = getDist(x[i], y[i], x[j], y[j]);
                g[i][j] = between <= r[i] + r[j] ? 0 : between - (r[i] + r[j]);
                g[j][i] = g[i][j];
            }
        }
    }

    vector<double> dist(n+2, INF);
    dist[0] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (int nv = 0; nv < n+2; ++nv) {
            if (v == nv) continue;
            if (dist[v] + g[v][nv] < dist[nv]) {
                dist[nv] = dist[v] + g[v][nv];
                que.emplace(dist[nv], nv);
            }
        }
    }

    cout << setprecision(15) << dist[n+1] << endl;

    return 0;
}