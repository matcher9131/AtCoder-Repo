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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        c[2 * i] = a[i];
        c[2 * i + 1] = b[i];
    }

    sort(c.begin(), c.end());
    auto it = unique(c.begin(), c.end());
    c.erase(it, c.end());

    vector<int> za(n), zb(n);
    for (int i = 0; i < n; ++i) {
        za[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        zb[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
    }

    vector<int> d(c.size() + 1);
    for (int i = 0; i < n; ++i) {
        ++d[za[i]];
        --d[zb[i] + 1];
    }
    for (int i = 1; i < d.size(); ++i) {
        d[i] += d[i - 1];
    }

    cout << *max_element(d.begin(), d.end()) << endl;

    return 0;
}