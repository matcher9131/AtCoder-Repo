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

constexpr int INF = 1000;

int main() {
    int m;
    cin >> m;
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];

    vector<vector<int>> pattern(10, vector<int>(3 * m));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < m; ++j) {
            pattern[(int)(s[i][j] - '0')][j] |= 1 << i;
            pattern[(int)(s[i][j] - '0')][j + m] |= 1 << i;
            pattern[(int)(s[i][j] - '0')][j + 2 * m] |= 1 << i;
        }
    }

    vector<int> c(10);
    vector<int> p(10);
    auto getTime = [&](int d) {
        for (int j = 0; j < 3 * m; ++j) {
            if (pattern[d][j] > 0) {
                ++c[d];
                p[d] |= pattern[d][j];
                if (c[d] >= 3 && p[d] == 7) return j;
            }
        }
        return INF;
    };

    int ans = INF;
    for (int d = 0; d < 10; ++d) {
        ans = min(ans, getTime(d));
    }
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}