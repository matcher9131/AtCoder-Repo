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
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    constexpr int INF = 1e8;
    vector<vector<bool>> v(h, vector<bool>(w));
    vector<vector<int>> dist(h, vector<int>(w, INF));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == 'H') {
                dist[i][j] = 0;
                // dist, i, j
                priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
                q.emplace(0, i, j);
                while (!q.empty()) {
                    auto [cd, i, j] = q.top();
                    q.pop();
                    if (cd > dist[i][j]) continue;
                    vector<pair<int, int>> next;
                    if (i > 0 && s[i-1][j] == '.') next.emplace_back(i-1, j);
                    if (i < h - 1 && s[i+1][j] == '.') next.emplace_back(i+1, j);
                    if (j >0 && s[i][j-1] == '.') next.emplace_back(i, j-1);
                    if (j < w - 1 && s[i][j+1] == '.') next.emplace_back(i, j+1);
                    for (const auto& [ni, nj] : next) {
                        if (dist[i][j] + 1 < dist[ni][nj]) {
                            dist[ni][nj] = dist[i][j] + 1;
                            q.emplace(dist[ni][nj], ni, nj);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (dist[i][j] <= d) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}