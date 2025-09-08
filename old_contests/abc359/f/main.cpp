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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> order(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(3 * a[0], 0);
    order[0] = 1;
    que.emplace(3 * a[1], 1);
    order[1] = 1;

    for (int i = 2; i < n; ++i) {
        auto [_, j] = que.top();
        que.pop();
        ++order[j];
        que.emplace(a[j] * (2 * order[j] + 1), j);
        order[i] = 1;
        que.emplace(3 * a[i], i);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += order[i] * order[i] * a[i];
    }

    cout << ans << endl;
    return 0;
}