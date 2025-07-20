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
    int na, nb, nc, k;
    cin >> na >> nb >> nc >> k;
    vector<ll> a(na), b(nb), c(nc);
    for (int i = 0; i < na; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < nc; ++i) {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    
    vector<ll> ans;
    priority_queue<tuple<ll, int, int, int>> que;
    set<tuple<int, int, int>> used;
    que.emplace(a[0] + b[0] + c[0], 0, 0, 0);

    while (!que.empty() && (int)ans.size() < k) {
        auto [val, ai, bi, ci] = que.top();
        que.pop();
        ans.push_back(val);
        if (ai+1 < na && !used.contains({ai+1, bi, ci})) {
            que.emplace(a[ai+1] + b[bi] + c[ci], ai+1, bi, ci);
            used.emplace(ai+1, bi, ci);
        }
        if (bi+1 < nb && !used.contains({ai, bi+1, ci})) {
            que.emplace(a[ai] + b[bi+1] + c[ci], ai, bi+1, ci);
            used.emplace(ai, bi+1, ci);
        }
        if (ci+1 < nc && !used.contains({ai, bi, ci+1})) {
            que.emplace(a[ai] + b[bi] + c[ci+1], ai, bi, ci+1);
            used.emplace(ai, bi, ci+1);
        }
    }

    for (const ll val : ans) {
        cout << val << endl;
    }

    return 0;
}