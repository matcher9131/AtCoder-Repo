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
    int h, w, n;
    string t;
    cin >> h >> w >> n >> t;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    int ans = 0;
    for (int si = 1; si < h-1; ++si) {
        for (int sj = 1; sj < w-1; ++sj) {
            if (s[si][sj] == '#') continue;
            int i = si, j = sj;
            bool ok = true;
            for (int k = 0; k < n; ++k) {
                switch (t[k]) {
                    case 'L': --j; break;
                    case 'R': ++j; break;
                    case 'U': --i; break;
                    case 'D': ++i; break;
                    default: break;
                }
                if (s[i][j] == '#') {
                    ok = false;
                    break;
                }
            }
            if (ok) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}