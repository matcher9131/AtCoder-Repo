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
    vector<vector<int>> p(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> p[i][j];
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << h); ++bit) {
        int a = 0;
        for (int i = 0; i < h; ++i) {
            if (bit & (1 << i)) ++a;
        }
        vector<int> num(h * w + 1);
        for (int j = 0; j < w; ++j) {
            int t = -1;
            bool bb = true;
            for (int i = 0; i < h; ++i) {
                if (bit & (1 << i)) {
                    if (t == -1) t = p[i][j];
                    else if (t != p[i][j]) {
                        bb = false;
                        break;
                    }
                }
            }
            if (bb && t >= 0) ++num[t];
        }
        ans = max(ans, a * *max_element(num.begin(), num.end()));
    }

    cout << ans << endl;

    return 0;
}