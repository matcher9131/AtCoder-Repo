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
    int n;
    cin >> n;
    int m = 1000;
    vector<vector<int>> a(m + 1, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++a[x1][y1];
        ++a[x2][y2];
        --a[x1][y2];
        --a[x2][y1];
    }

    for (int x = 0; x <= m; ++x) {
        for (int y = 0; y < m; ++y) {
            a[x][y + 1] += a[x][y];
        }
    }
    for (int y = 0; y <= m; ++y) {
        for (int x = 0; x < m; ++x) {
            a[x + 1][y] += a[x][y];
        }
    }

    vector<int> ans(n + 1);
    for (int x = 0; x <= m; ++x) {
        for (int y = 0; y <= m; ++y) {
            ++ans[a[x][y]];
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}