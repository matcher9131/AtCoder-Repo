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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> b[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < h - 1; ++i) {
        for (int j = 0; j < w - 1; ++j) {
            int d = b[i][j] - a[i][j];
            ans += abs(d);
            a[i][j+1] += d;
            a[i+1][j] += d;
            a[i+1][j+1] += d;
        }
        if (a[i][w-1] != b[i][w-1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int j = 0; j < w; ++j) {
        if (a[h-1][j] != b[h-1][j]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;

    return 0;
}