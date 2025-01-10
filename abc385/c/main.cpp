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
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int ans = 1;

    for (int m = 1; m < n; ++m) {
        for (int r = 0; r < m; ++r) {
            int ch = 0;
            int suc = 0;
            // i = m * q + r
            for (int i = r; i < n; i += m) {
                if (h[i] != ch) {
                    ch = h[i];
                    suc = 0;
                }
                ++suc;
                ans = max(ans, suc);
            }
        }
    }
    

    cout << ans << endl;

    return 0;
}