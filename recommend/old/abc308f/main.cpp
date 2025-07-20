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
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> p(n);
    vector<ll> l(m);
    vector<ll> d(m);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
    }
    sort(p.begin(), p.end());

    vector<pair<int, int>> coupons;
    for (int i = 0; i < m; ++i) {
        coupons.emplace_back(l[i], d[i]);
    }
    sort(coupons.begin(), coupons.end());

    ll answer = 0;
    priority_queue<ll> que;
    int ci = 0;
    for (const ll price : p) {
        // pもcouponsも昇順なので利用可能なクーポンの数はci = 0からインデックス順に増えていく
        // 割引額のみpriority_queに突っ込んで高い順に使う
        for (; ci < m && coupons[ci].first <= price; ++ci) {
            que.push(coupons[ci].second);
        }
        if (!que.empty()) {
            answer += price - que.top();
            que.pop();
        } else {
            answer += price;
        }
    }

    cout << answer << endl;

    return 0;
}