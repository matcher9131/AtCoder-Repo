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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());

    vector<int> b(m);
    copy(a.begin(), a.begin() + m, b.begin());
    for (int i = 0; i < n - m; ++i) {
        b[m - 1 - i] += a[m + i];
    }

    ll ans = accumulate(b.begin(), b.end(), 0LL, [](ll acc, ll value) {
        return acc + value * value;
    });
    cout << ans << endl;

    return 0;
}