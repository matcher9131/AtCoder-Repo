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

constexpr int INF = 1e8;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    int ans = INF;
    if (w >= k) {
        for (int i = 0; i < h; ++i) {
            int co = 0, cx = 0;
            for (int j = 0; j < k; ++j) {
                if (s[i][j] == 'x') ++cx;
                else if (s[i][j] == 'o') ++co;
            }
            if (cx == 0) ans = min(ans, k - co);
            for (int j = 0; j < w - k; ++j) {
                if (s[i][j] == 'x') --cx;
                else if (s[i][j] == 'o') --co;
                if (s[i][j+k] == 'x') ++cx;
                else if (s[i][j+k] == 'o') ++co;
                if (cx == 0) ans = min(ans, k - co);
            }
        }
    }
    if (h >= k) {
        for (int j = 0; j < w; ++j) {
            int co = 0, cx = 0;
            for (int i = 0; i < k; ++i) {
                if (s[i][j] == 'x') ++cx;
                else if (s[i][j] == 'o') ++co;
            }
            if (cx == 0) ans = min(ans, k - co);
            for (int i = 0; i < h - k; ++i) {
                if (s[i][j] == 'x') --cx;
                else if (s[i][j] == 'o') --co;
                if (s[i+k][j] == 'x') ++cx;
                else if (s[i+k][j] == 'o') ++co;
                if (cx == 0) ans = min(ans, k - co);
            }
        }
    }    

    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}