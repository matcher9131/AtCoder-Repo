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
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i] += i;
    }

    unordered_map<int, stack<int>> m;
    atcoder::fenwick_tree<int> fw(n);
    for (int i = 0; i < n; ++i) {
        m[a[i]].push(i);
        fw.add(i, 1);
    }
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (!m.contains(b[i]) || m[b[i]].empty()) {
            cout << -1 << endl;
            return 0;
        }
        int j = m[b[i]].top();
        m[b[i]].pop();
        fw.add(j, -1);
        ans += fw.sum(j, n);
    }

    cout << ans << endl;

    return 0;
}