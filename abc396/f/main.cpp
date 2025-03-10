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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    atcoder::fenwick_tree<ll> fw(m+1);
    vector<vector<int>> map(m);
    for (int i = 0; i < n; ++i) {
        ans += i - fw.sum(0, a[i] + 1);
        fw.add(a[i], 1);
        map[a[i]].push_back(i);
    }

    cout << ans << endl;

    for (int k = 1; k < m; ++k) {
        for (const auto i : map[m - k]) {
            int left = lower_bound(map[m-k].begin(), map[m-k].end(), i) - map[m-k].begin();
            int right = map[m-k].size() - left - 1;
            ans += i - left;
            ans -= n - 1 - i - right;
        }
        cout << ans << endl;
    }

    return 0;
}