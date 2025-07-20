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

constexpr ll INF = 1e16;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<ll>> d(c, vector<ll>(c));
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> d[i][j];
        }
    }
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            --g[i][j];
        }
    }
    
    vector<vector<ll>> sd(3, vector<ll>(c));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int ci = 0; ci < c; ++ci) {
                sd[(i+j+2)%3][ci] += d[g[i][j]][ci];
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i == j) continue;
            for (int k = 0; k < c; ++k) {
                if (i == k || j == k) continue;
                ans = min(ans, sd[0][i] + sd[1][j] + sd[2][k]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}