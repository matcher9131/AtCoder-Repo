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

constexpr int INF = 1e8;

int main() {
    int n, m, cr;
    cin >> n >> m >> cr;
    vector<int> r(cr);
    for (int i = 0; i < cr; ++i) {
        cin >> r[i];
        --r[i];
    }
    sort(r.begin(), r.end());
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        d[a][b] = c;
        d[b][a] = c;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int answer = INF;
    do {
        int dist = 0;
        for (int i = 0; i < cr - 1; ++i) {
            dist += d[r[i]][r[i + 1]];
        }
        answer = min(answer, dist);
    } while (next_permutation(r.begin(), r.end()));

    cout << answer << endl;

    return 0;
}