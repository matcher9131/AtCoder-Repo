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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<ll> oneIndex(m);
    oneIndex[0] = 0;
    for (ll i = 0; i < m-1; ++i) {
        if (oneIndex[i] == a[i]) {
            oneIndex[i+1] = oneIndex[i] + 1;
        } else if (oneIndex[i] == a[i] + 1) {
            oneIndex[i+1] = oneIndex[i] - 1;
        } else {
            oneIndex[i+1] = oneIndex[i];
        }
    }

    vector<ll> ans(m);
    vector<ll> r(n);
    for (ll i = 0; i < n; ++i) {
        r[i] = i;
    }

    for (ll i = m - 1; i >= 0; --i) {
        ans[i] = r[oneIndex[i]];
        swap(r[a[i]], r[a[i]+1]);
    }

    for (ll i = 0; i < m; ++i) {
        cout << ans[i]+1 << endl;
    }

    return 0;
}