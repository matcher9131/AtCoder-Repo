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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> l(n + 1), r(n + 1);
    ++l[a[0]];
    for (int i = 2; i < n; ++i) {
        ++r[a[i]];
    }

    ll s = 0;
    for (int i = 1; i <= n; ++i) {
        s += l[i] * r[i];
    }

    ll ans = 0;
    for (int j = 1; j < n - 1; ++j) {
        ans += s - l[a[j]] * r[a[j]];
        s += (a[j] == a[j + 1]) ? r[a[j + 1]] - l[a[j]] - 1 : r[a[j]] - l[a[j + 1]];
        ++l[a[j]];
        --r[a[j + 1]];
    }

    cout << ans << endl;

    return 0;
}