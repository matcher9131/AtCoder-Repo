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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());

    priority_queue<tuple<ll, ll, ll, ll>> que;
    set<tuple<ll, ll, ll>> visited;
    que.emplace(a[0]*b[0] + b[0]*c[0] + c[0]*a[0], 0, 0, 0);
    visited.emplace(0, 0, 0);
    ll count = 0;
    while (!que.empty()) {
        auto [val, x, y, z] = que.top();
        que.pop();
        ++count;
        if (count == k) {
            cout << val << endl;
            return 0;
        }
        if (x < n-1 && !visited.contains({ x+1, y, z })) {
            que.emplace(a[x+1]*b[y] + b[y]*c[z] + c[z]*a[x+1], x+1, y, z);
            visited.emplace(x+1, y, z);
        }
        if (y < n-1 && !visited.contains({ x, y+1, z })) {
            que.emplace(a[x]*b[y+1] + b[y+1]*c[z] + c[z]*a[x], x, y+1, z);
            visited.emplace(x, y+1, z);
        }
        if (z < n-1 && !visited.contains({ x, y, z+1 })) {
            que.emplace(a[x]*b[y] + b[y]*c[z+1] + c[z+1]*a[x], x, y, z+1);
            visited.emplace(x, y, z+1);
        }
    }

    return 0;
}