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
    vector<vector<int>> g(n, vector<int>());
    vector<int> a(n), b(n);
    for (int i = 0; i < n - 1; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
        a[i] = ai;
        b[i] = bi;
    }
    int q;
    cin >> q;
    vector<int> t(q), e(q), x(q);
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> e[i] >> x[i];
        --e[i];
    }

    vector<int> pre(n, -1), post(n, -1);
    function<void(int, int &)> dfs = [&](int from, int &timestamp) {
        pre[from] = timestamp;
        ++timestamp;
        for (const int to : g[from]) {
            if (pre[to] >= 0) continue;
            dfs(to, timestamp);
        }
        post[from] = timestamp;
        ++timestamp;
    };
    int timestamp = 0;
    dfs(0, timestamp);

    vector<ll> s(2 * n);
    for (int i = 0; i < q; ++i) {
        int v1 = a[e[i]], v2 = b[e[i]];
        if (t[i] == 2) swap(v1, v2);
        if (pre[v1] > pre[v2]) {
            // v1はv2の子
            s[pre[v1]] += x[i];
            s[post[v1]] -= x[i];
        } else {
            // v1はv2の親
            s[0] += x[i];
            s.back() -= x[i];
            s[pre[v2]] -= x[i];
            s[post[v2]] += x[i];
        }
    }

    for (int i = 1; i < s.size(); ++i) {
        s[i] += s[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        cout << s[pre[i]] << endl;
    }

    return 0;
}