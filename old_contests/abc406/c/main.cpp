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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> high, low;
    for (int i = 1; i < n-1; ++i) {
        if (a[i-1] < a[i] && a[i] > a[i+1]) high.push_back(i);
        else if (a[i-1] > a[i] && a[i] < a[i+1]) low.push_back(i);
    }

    if (high.empty() || low.empty()) {
        cout << 0 << endl;
        return 0;
    }

    if (high[0] < low[0]) low.insert(low.begin(), 0);
    if (high.back() < low.back()) high.push_back(n-1);

    int m = min(high.size(), low.size());
    ll ans = 0;
    for (int i = 0; i < m-1; ++i) {
        ans += (ll)(high[i] - low[i]) * (high[i+1] - low[i+1]);
    }

    cout << ans << endl;
    return 0;
}