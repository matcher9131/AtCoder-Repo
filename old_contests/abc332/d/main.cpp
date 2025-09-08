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

    map<vector<vector<int>>, int> dist;
    dist[a] = 0;
    queue<vector<vector<int>>> que;
    que.push(a);
    while (!que.empty()) {
        auto c = que.front();
        que.pop();
        for (int i = 0; i < h-1; ++i) {
            auto ci = c;
            swap(ci[i], ci[i+1]);
            if (!dist.contains(ci)) {
                dist[ci] = dist[c] + 1;
                que.push(ci);
            }
        }
        for (int j = 0; j < w-1; ++j) {
            auto ci = c;
            for (int i = 0; i < h; ++i) {
                swap(ci[i][j], ci[i][j+1]);
            }
            if (!dist.contains(ci)) {
                dist[ci] = dist[c] + 1;
                que.push(ci);
            }
        }
    }

    cout << (dist.contains(b) ? dist[b] : -1) << endl;
    return 0;
}