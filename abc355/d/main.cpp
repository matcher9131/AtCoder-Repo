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
    int n2 = 2 * n;
    // l, r
    vector<pair<int, int>> a(n);
    vector<int> coord(n2);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        a[i] = { l, r };
        coord[2*i] = l;
        coord[2*i+1] = r;
    }
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        int l = lower_bound(coord.begin(), coord.end(), a[i].first) - coord.begin();
        int r = lower_bound(coord.begin(), coord.end(), a[i].second) - coord.begin();
        b[i] = { l, r };
    }
    sort(b.begin(), b.end());

    atcoder::fenwick_tree<int> fw(n2); 
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto [l, r] = b[i];
        ans += fw.sum(l, n2);
        fw.add(r, 1);
    }

    cout << ans << endl;
    return 0;
}