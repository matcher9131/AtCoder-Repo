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
    int n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    sort(b.begin(), b.end());

    vector<ll> sb(m + 1);
    for (int j = 0; j < m; ++j) {
        sb[j + 1] = sb[j] + b[j];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(b.begin(), b.end(), p - a[i]);
        int c = it - b.begin();
        ans += c * a[i] + sb[c] + (ll)p * (m - c);
    }

    cout << ans << endl;

    return 0;
}
