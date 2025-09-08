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
#include <atcoder/dsu>
using namespace std;
using ll = long long;


int main() {
    int n, nq;
    cin >> n >> nq;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    atcoder::dsu d(n+1500);
    // dist, i, j
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> que;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            que.emplace(abs(x[i] - x[j]) + abs(y[i] - y[j]), i, j);
        }
    }

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            ll a, b;
            cin >> a >> b;
            for (int i = 0; i < (int)x.size(); ++i) {
                que.emplace(abs(x[i] - a) + abs(y[i] - b), i, (int)x.size());
            }
            x.push_back(a);
            y.push_back(b);
        } else if (k == 2) {
            if (que.empty()) {
                cout << -1 << endl;
            } else {
                ll kMin = 1e18;
                while (!que.empty()) {
                    auto [k, i, j] = que.top();
                    que.pop();
                    if (d.same(i, j)) continue;
                    if (k <= kMin) {
                        kMin = k;
                        d.merge(i, j);
                    } else {
                        que.emplace(k, i, j);
                        break;
                    }
                }
                cout << kMin << endl;
            }
        } else {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            cout << (d.same(u, v) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}