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
using namespace std;
using ll = long long;

constexpr ll INF = 1e16;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    vector<tuple<int, int, ll>> edge(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a;
        --b;
        edge[i] = make_tuple(a, b, c);
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = 0;
    for (const auto [from, to, cost] : edge) {
        for (int i = 0; i < n; ++i) {
            if (dist[from][i] + dist[i][to] <= cost) {
                ++answer;
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}