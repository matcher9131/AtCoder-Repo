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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<ll> b(n*m);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> a[i][j];
            b[i*m+j] = a[i][j];
        }
    }
    sort(b.begin(), b.end());
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            a[i][j] = lower_bound(b.begin(), b.end(), a[i][j]) - b.begin();
        }
    }

    ll ans = n * (n-1) / 2 * m;
    atcoder::fenwick_tree<ll> fw(n*m);
    for (ll i = n - 1; i >= 0; --i) {
        for (ll j = 0; j < m; ++j) {
            ans += fw.sum(0, a[i][j]);
            ans += j * (n-1 - i);
        }
        for (ll j = 0; j < m; ++j) {
            fw.add(a[i][j], 1);
        }
    }

    cout << ans << endl;
    return 0;
}