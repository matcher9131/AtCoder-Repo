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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = 0, r = 0;
    unordered_map<int, int> m;
    int ans = 0;
    while (r < n) {
        if (m.size() == k) {
            if (m.contains(a[r])) {
                ++m[a[r]];
                ++r;
            } else {
                ans = max(ans, r - l);
                while (l <= r && m.size() >= k) {
                    --m[a[l]];
                    if (m[a[l]] == 0) m.erase(a[l]);
                    ++l;
                }
            }
        } else {
            ++m[a[r]];
            ++r;
        }
    }
    ans = max(ans, r - l);

    cout << ans << endl;

    return 0;
}