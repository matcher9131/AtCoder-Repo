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

ll answer = 0;
int n;
vector<ll> d;
vector<vector<int>> g;

void dfs(int i, int j, ll sum, int visited) {
    visited |= 1 << i;
    visited |= 1 << j;
    sum += d[i * n + j];
    //
    // cout << "i = " << i << ", j = " << j << ", d = " << d[i * n + j] << ", sum = " << sum << endl;
    //
    answer = max(answer, sum);
    for (const int to : g[i * n + j]) {
        int ni = to / n;
        int nj = to % n;
        if (visited & (1 << ni)) continue;
        if (visited & (1 << nj)) continue;
        dfs(ni, nj, sum, visited);
    }
}

int main() {
    cin >> n;
    d = vector<ll>(n * n);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> d[i * n + j];
        }
    }

    g = vector<vector<int>>(n * n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int i2 = i + 1; i2 < n - 1; ++i2) {
                for (int j2 = i2 + 1; j2 < n; ++j2) {
                    if (i2 == i || j2 == i || i2 == j || j2 == j) continue;
                    g[i * n + j].push_back(i2 * n + j2);
                }
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        dfs(0, i, 0, 0);
    }
    for (int i = 2; i < n; ++i) {
        dfs(1, i, 0, 0);
    }

    cout << answer << endl;

    return 0;
}
