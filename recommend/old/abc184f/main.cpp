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
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll m = n/2;
    vector<ll> former;
    for (ll bit = 0; bit < 1LL << m; ++bit) {
        ll sum = 0;
        for (ll i = 0; i < m; ++i) {
            if (bit & (1LL << i)) sum += a[i];
        }
        if (sum <= t) former.push_back(sum);
    }
    sort(former.begin(), former.end());

    ll ans = 0;
    for (ll bit = 0; bit < 1LL << (n-m); ++bit) {
        ll sum = 0;
        for (ll i = 0; i < n-m; ++i) {
            if (bit & (1LL << i)) sum += a[m+i];
        }
        if (sum > t) continue;
        auto it = upper_bound(former.begin(), former.end(), t-sum);
        if (it == former.begin()) continue;
        --it;
        ans = max(ans, *it + sum);
    }

    cout << ans << endl;
    return 0;
}