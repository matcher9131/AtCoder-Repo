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
    // [l, r)
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        ++r[i];
    }

    double ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = l[i]; k < r[i]; ++k) {
                ans += (double)(max(min(k, r[j]) - l[j], 0)) / (r[j] - l[j]) / (r[i] - l[i]);
            }
        }
    }

    cout << setprecision(15) << ans << endl;

    return 0;
}