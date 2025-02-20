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
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<bool>> waterfront(h, vector<bool>(w));
    int ans = h * w;
    // a[i][j], i, j
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
    for (int i = 0; i < h; ++i) {
        if (!waterfront[i][0]) {
            waterfront[i][0] = true;
            que.emplace(a[i][0], i , 0);
        }
        if (!waterfront[i][w-1]) {
            waterfront[i][w-1] = true;
            que.emplace(a[i][w-1], i, w-1);
        }
    }
    for (int j = 1; j < w - 1; ++j) {
        if (!waterfront[0][j]) {
            waterfront[0][j] = true;
            que.emplace(a[0][j], 0, j);
        }
        if (!waterfront[h-1][j]) {
            waterfront[h-1][j] = true;
            que.emplace(a[h-1][j], h-1, j);
        }
    }
    auto emplaceIfNotYet = [&](int i, int j) -> void {
        if (i >= 0 && i < h && j >= 0 && j < w && !waterfront[i][j]) {
            que.emplace(a[i][j], i, j);
            waterfront[i][j] = true;
        }
    };

    for (int yy = 1; yy <= y; ++yy) {
        while (!que.empty()) {
            auto [h, i, j] = que.top();
            if (h > yy) break;
            que.pop();
            --ans;
            emplaceIfNotYet(i-1, j);
            emplaceIfNotYet(i+1, j);
            emplaceIfNotYet(i, j-1);
            emplaceIfNotYet(i, j+1);
        }
        cout << ans << endl;
    }

    return 0;
}