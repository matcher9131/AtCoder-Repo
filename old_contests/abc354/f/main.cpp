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
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> l(n), r(n);
        vector<int> dpl, dpr;
        for (int i = 0; i < n; ++i) {
            auto itl = lower_bound(dpl.begin(), dpl.end(), a[i]);
            l[i] = itl - dpl.begin();
            if (itl == dpl.end()) {
                dpl.push_back(a[i]);
            } else {
                *itl = a[i];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            auto itr = lower_bound(dpr.begin(), dpr.end(), -a[i]);
            r[i] = itr - dpr.begin();
            if (itr == dpr.end()) {
                dpr.push_back(-a[i]);
            } else {
                *itr = -a[i];
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (l[i] + r[i] + 1 == (int)dpl.size()) {
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i] + 1 << " \n"[i == (int)ans.size() - 1];
        }
    }

    return 0;
}