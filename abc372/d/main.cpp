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

    vector<int> t;
    vector<int> ans(n);
    for (int i = n - 1; i >= 1; --i) {
        auto it = upper_bound(t.rbegin(), t.rend(), h[i]);
        int rd = it - t.rbegin();
        int d = t.size() - rd;
        t.resize(d);
        t.push_back(h[i]);
        ans[i - 1] = d + 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}