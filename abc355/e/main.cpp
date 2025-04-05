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

int inline pmod(int x, int y) {
    int r = x % y;
    return r >= 0 ? r : r + y;
}

int main() {
    int n;
    ll l, r;
    cin >> n >> l >> r;
    int m = 1 << n;

    vector<vector<int>> g(m + 1);
    for (int i = 0; i <= n; ++i) {
        for (int x = 0; x < m; x += (1 << i)) {
            int y = x + (1 << i);
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    vector<int> prev(g.size(), -1);
    prev[r + 1] = -2;
    queue<int> que;
    que.push(r + 1);
    while (!que.empty()) {
        int from = que.front();
        que.pop();
        for (const int to : g[from]) {
            if (prev[to] != -1) continue;
            prev[to] = from;
            que.push(to);
        }
    }

    int ans = 0;
    int current = l;
    while (current != r + 1) {
        int x = current, y = prev[current];
        int sign = 1;
        if (x > y) {
            swap(x, y);
            sign = -1;
        }
        int i = countr_zero((unsigned)(y - x));
        int j = x >> i;

        cout << "? " << i << " " << j << endl;
        int t;
        cin >> t;
        if (t == -1) return 0;
        ans += t * sign;

        current = y;
    }

    cout << "! " << pmod(ans, 100) << endl;

    return 0;
}