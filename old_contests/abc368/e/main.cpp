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
    int n, m;
    ll x0;
    cin >> n >> m >> x0;
    vector<int> a(m), b(m);
    vector<ll> s(m), t(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> s[i] >> t[i];
        --a[i];
        --b[i];
    }

    vector<ll> x(m);
    x[0] = x0;
    // 時刻, 到着 = false, 電車番号
    priority_queue<tuple<ll, bool, int>, vector<tuple<ll, bool, int>>, greater<tuple<ll, bool, int>>> que;
    // 駅番号, 最も遅く到着した電車の実際の到着時刻
    unordered_map<int, ll> lastArrived;
    for (int i = 0; i < m; ++i) {
        que.emplace(s[i], true, i);
        que.emplace(t[i], false, i);
    }
    // 電車0を実際に遅らせる
    s[0] += x0;
    t[0] += x0;
    while (!que.empty()) {
        auto [time, leaving, i] = que.top();
        que.pop();
        if (leaving) {
            if (i == 0) continue;
            int from = a[i];
            if (lastArrived.contains(from)) {
                x[i] = max(x[i], lastArrived[from] - time);
                s[i] += x[i];
                t[i] += x[i];
            }
        } else {
            int to = b[i];
            lastArrived[to] = max(lastArrived[to], t[i]);
        }
    }

    for (int i = 1; i < m; ++i) {
        cout << x[i] << " \n"[i == m - 1];
    }

    return 0;
}