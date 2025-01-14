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
#include <bit>
using namespace std;
using ll = long long;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }

    auto search = [&](int start) {
        // dp[訪れたマスNo.の集合][最後にいるマスNo.] = そのようなたどり方ができるかどうか
        vector<vector<bool>> dp(1 << (h * w), vector<bool>(h * w));

        stack<pair<int, int>> s;
        s.emplace(1 << start, start);
        while (!s.empty()) {
            auto [visited, last] = s.top();
            s.pop();
            if (dp[visited][last]) continue;
            dp[visited][last] = true;
            int i = last / w;
            int j = last % w;
            if (i > 0 && g[i-1][j] == '.') {
                int num = (i - 1) * w + j;
                if ((visited & 1 << num) == 0) {
                    s.emplace(visited | (1 << num), num);
                }
            }
            if (i < h - 1 && g[i+1][j] == '.') {
                int num = (i + 1) * w + j;
                if ((visited & 1 << num) == 0) {
                    s.emplace(visited | (1 << num), num);
                }
            }
            if (j > 0 && g[i][j-1] == '.') {
                int num = i * w + j - 1;
                if ((visited & 1 << num) == 0) {
                    s.emplace(visited | (1 << num), num);
                }
            }
            if (j < w - 1 && g[i][j+1] == '.') {
                int num = i * w + j + 1;
                if ((visited & 1 << num) == 0) {
                    s.emplace(visited | (1 << num), num);
                }
            }
        }
        
        int si = start / w;
        int sj = start % w;
        vector<int> goals;
        int ans = -1;
        if (si > 0 && g[si - 1][sj] == '.') {
            goals.push_back((si - 1) * w + sj);
        }
        if (si < h - 1 && g[si + 1][sj] == '.') {
            goals.push_back((si + 1) * w + sj);
        }
        if (sj > 0 && g[si][sj - 1] == '.') {
            goals.push_back(si * w + sj - 1);
        }
        if (sj < w - 1 && g[si][sj + 1] == '.') {
            goals.push_back(si * w + sj + 1);
        }
        for (int i = 0; i < dp.size(); ++i) {
            for (const int goal : goals) {
                if (dp[i][goal]) {
                    ans = max(ans, popcount((unsigned int)i));
                }
            }
        }
        
        return ans;
    };
    
    int ans = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i][j] == '#') continue;
            ans = max(ans, search(i * w + j));
        }
    }

    cout << (ans > 2 ? ans : -1) << endl;

    return 0;
}