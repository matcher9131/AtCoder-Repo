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
    ll m;
    cin >> n >> m;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    // 現在の価格, 今から買うのが何個目か
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    for (int i = 0; i < n; ++i) {
        que.emplace(p[i], 1);
    }

    ll ans = 0;
    while (true) {
        auto [price, k] = que.top();
        que.pop();
        if (price > m) {
            cout << ans << endl;
            return 0;
        }

        m -= price;
        ++ans;
        que.emplace(price / (2 * k - 1) * (2 * k + 1), k + 1);
    }

    return 0;
}