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
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

int addMod(int x, int y) {
    return (x + y) % MOD;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<vector<int>> r(h, vector<int>(w));
    vector<vector<int>> d(h, vector<int>(w));
    vector<vector<int>> rd(h, vector<int>(w));
    vector<vector<int>> dp(h, vector<int>(w));
    dp[0][0] = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 && j == 0) continue;
            if (s[i][j] == '#') continue;
            if (j > 0) r[i][j] = addMod(r[i][j - 1], dp[i][j - 1]);
            if (i > 0) d[i][j] = addMod(d[i - 1][j], dp[i - 1][j]);
            if (i > 0 && j > 0) rd[i][j] = addMod(rd[i - 1][j - 1], dp[i - 1][j - 1]);
            dp[i][j] = addMod(addMod(r[i][j], d[i][j]), rd[i][j]);
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}