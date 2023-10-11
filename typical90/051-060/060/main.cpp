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

constexpr int INF = 1e8;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[j]: 1番目からi番目までの最長増加部分列で長さがj + 1になるようなものにおける末項の最小値
    vector<int> dpl(n, INF);
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        int index = lower_bound(dpl.begin(), dpl.end(), a[i]) - dpl.begin();
        dpl[index] = a[i];
        l[i] = index + 1;
    }
    reverse(a.begin(), a.end());
    vector<int> dpr(n, INF);
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        int index = lower_bound(dpr.begin(), dpr.end(), a[i]) - dpr.begin();
        dpr[index] = a[i];
        r[i] = index + 1;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, l[i] + r[n - i - 1] - 1);
    }
    cout << ans << endl;

    return 0;
}