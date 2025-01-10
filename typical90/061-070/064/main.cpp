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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> l(q);
    vector<int> r(q);
    vector<ll> v(q);
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i] >> v[i];
        --l[i];
        --r[i];
    }
    
    vector<ll> d(n-1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = a[i + 1] - a[i];
    }
    ll ans = 0;
    for (const ll di : d) {
        ans += abs(di);
    }

    for (int i = 0; i < q; ++i) {
        if (l[i] > 0) {
            ll absBefore = abs(d[l[i] - 1]);
            d[l[i] - 1] += v[i];
            ans += abs(d[l[i] - 1]) - absBefore;
        }
        if (r[i] < n - 1) {
            ll absBefore = abs(d[r[i]]);
            d[r[i]] -= v[i];
            ans += abs(d[r[i]]) - absBefore;
        }
        cout << ans << endl;
    }

    return 0;
}