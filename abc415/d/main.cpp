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
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    for (ll i = 0; i < m; ++i) {
        que.emplace(a[i] - b[i], a[i]);
    }

    ll ans = 0;
    while (!que.empty()) {
        auto [d, need] = que.top();
        que.pop();
        if (n < need) continue;
        ll count = (n - need + d-1) / d;
        ans += count;
        n -= d * count;
        if (n >= need) {
            ++ans;
            n -= d;
        }
    }

    cout << ans << endl;
    return 0;
}