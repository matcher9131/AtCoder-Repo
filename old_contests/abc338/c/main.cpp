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
    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int ans = 0;
    for (int x = 0; x <= 1e6; ++x) {
        int yMin = 1e8;
        for (int i = 0; i < n; ++i) {
            if (q[i] < x * a[i]) {
                yMin = -1;
                break;
            } else if (b[i] == 0) {
                continue;
            } else {
                yMin = min(yMin, (q[i] - x*a[i]) / b[i]);
            }
        }
        if (yMin == -1) break;
        ans = max(ans, x + yMin);
    }

    cout << ans << endl;
    return 0;
}