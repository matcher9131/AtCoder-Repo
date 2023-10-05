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
    vector<int> w(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int wm = 50;
    int bm = 50 * (50 + 1) / 2;
    vector<vector<int>> grundy(wm + 1, vector<int>(bm + 1));

    // (i, j) -> (i - 1, j + i) when i > 0
    // (i, j) -> (i, j - k) where 1 <= k <= [j/2]
    for (int i = 0; i <= wm; ++i) {
        for (int j = 0; j <= bm; ++j) {
            vector<int> v(bm + 2);
            if (i > 0 && j + i <= bm) v[grundy[i - 1][j + i]] = 1;
            for (int k = 1; k <= j / 2; ++k) {
                v[grundy[i][j - k]] = 1;
            }
            for (int k = 0; k <= bm; ++k) {
                if (v[k] == 0) {
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans ^= grundy[w[i]][b[i]];
    }
    cout << (ans == 0 ? "Second" : "First") << endl;

    return 0;
}