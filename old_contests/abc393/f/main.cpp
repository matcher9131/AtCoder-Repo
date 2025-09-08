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

constexpr int INF = 1e9 + 1;

int main() {
    int n, nq;
    cin >> n >> nq;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // r, x, index
    vector<tuple<int, int, int>> q(nq);
    for (int i = 0; i < nq; ++i) {
        int r, x;
        cin >> r >> x;
        --r;
        q[i] = { r, x, i };
    }
    sort(q.begin(), q.end());

    vector<int> ans(nq);
    vector<int> lis(n, INF);
    int index = 0;
    for (const auto& [r, x, qi] : q) {
        for (; index <= r; ++index) {
            auto it = lower_bound(lis.begin(), lis.end(), a[index]);
            *it = a[index];
        }
        ans[qi] = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
    }

    for (const int answer : ans) {
        cout << answer << endl;
    }

    return 0;
}