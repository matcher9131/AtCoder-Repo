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

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<vector<int>> a(h+1, vector<int>(w+1, 0));
    vector<vector<int>> b(h+1, vector<int>(w+1, 0));
    vector<vector<int>> c(h+1, vector<int>(w+1, 0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            a[i+1][j+1] = a[i][j+1] + a[i+1][j] - a[i][j] + (s[i][j] == '#' ? 1 : 0);
            b[i+1][j+1] = b[i][j+1] + b[i+1][j] - b[i][j] + (s[i][j] == '.' ? 1 : 0);
            c[i+1][j+1] = a[i+1][j+1] - b[i+1][j+1];
        }
    }

    int ans = 0;
    for (int i1 = 0; i1 < h; ++i1) {
        for (int j1 = 0; j1 < w; ++j1) {
            for (int i2 = i1+1; i2 <= h; ++i2) {
                for (int j2 = j1+1; j2 <=w; ++j2) {
                    int v1 = a[i2][j2] - a[i1][j2] - a[i2][j1] + a[i1][j1];
                    int v2 = b[i2][j2] - b[i1][j2] - b[i2][j1] + b[i1][j1];
                    if (v1 == v2) {
                        ++ans;
                        printf("[%d,%d) x [%d,%d)\n", i1, i2, j1, j2);
                        
                    }
                }
            }
        }
    }
    cout << ans << endl;

    // for (int i = 1; i <= h; ++i) {
    //     for (int j = 1; j <= w; ++j) {
    //         cout << c[i][j] << " \n"[j == w];
    //     }
    // }
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}