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

constexpr int M = 1e8;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    ll over = 0;
    for (int i = 0; i < n; ++i) {
        ans += (n - 1) * a[i];
        int j = lower_bound(a.begin(), a.end(), M - a[i]) - a.begin();
        over += min(n - j, n - i - 1);
    }
    ans -= M * over;

    cout << ans << endl;
    return 0;
}