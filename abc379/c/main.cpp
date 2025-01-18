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
    vector<ll> x(m), a(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
        --x[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<pair<ll, ll>> p(m);
    for (int i = 0; i < m; ++i) {
        p[i] = make_pair(x[i], a[i]);
    }
    sort(p.begin(), p.end(), greater<pair<ll, ll>>());

    ll done = n;
    ll count = 0;
    for (int i = 0; i < m; ++i) {
        auto [xi, ai] = p[i];
        if (done - ai < xi) {
            cout << -1 << endl;
            return 0;
        }
        // 初項: done - x[i] - a[i], 末項: done - x[i] - 1, 項数: a[i]
        count += (done - xi - ai + done - xi - 1LL) * ai / 2LL;
        done -= ai;
    }

    if (done > 0) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << count << endl;

    return 0;
}