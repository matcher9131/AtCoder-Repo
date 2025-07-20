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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());

    auto calc = [&](vector<int> &x, int mp) {
        int r = 1e8;
        for (int i = 0; i < x.size() - 2; ++i) {
            for (int j = i + 1; j < x.size() - 1; ++j) {
                for (int k = j + 1; k < x.size(); ++k) {
                    r = min(r, mp + abs(x[i] - c) + abs(x[j] - b) + abs(x[k] - a));
                }
            }
        }
        return r;
    };

    int ans = 1e8;
    stack<vector<int>> s;
    s.push(l);
    while (!s.empty()) {
        auto x = s.top();
        s.pop();
        ans = min(ans, calc(x, 10 * (n - x.size())));
        if (ans == 0) {
            cout << 0 << endl;
            return 0;
        }
        if (x.size() > 3) {
            for (int i = 0; i < x.size() - 1; ++i) {
                for (int j = i + 1; j < x.size(); ++j) {
                    vector<int> y = x;
                    int t = y[i] + y[j];
                    y.erase(y.begin() + j);
                    y.erase(y.begin() + i);
                    y.insert(lower_bound(y.begin(), y.end(), t), t);
                    s.push(y);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}