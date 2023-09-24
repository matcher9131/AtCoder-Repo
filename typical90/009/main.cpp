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

constexpr double PI = 3.1415926535897932384626433832795;

int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<double> t;
        t.reserve(n - 1);
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            t.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        }
        sort(t.begin(), t.end());
        for (int j = 0; j < n - 1; ++j) {
            double tk = t[j] + PI;
            if (tk > PI) tk -= 2 * PI;
            auto it = lower_bound(t.begin(), t.end(), tk);
            if (it == t.end()) it = t.begin();
            double ansr = abs(*it - t[j]);
            if (ansr > PI) ansr = 2 * PI - ansr;
            ans = max(ans, ansr);
            if (it == t.begin()) it = t.end();
            --it;
            double ansl = abs(*it - t[j]);
            if (ansl > PI) ansl = 2 * PI - ansl;
            ans = max(ans, ansl);
        }
    }

    cout << setprecision(15) << ans * 180.0 / PI << endl;

    return 0;
}