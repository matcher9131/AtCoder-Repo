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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> sumEven(n+1), sumOdd(n+1);
    for (ll i = 0; i < n; ++i) {
        if (i % 2) {
            sumOdd[i+1] = sumOdd[i] + a[i];
            sumEven[i+1] = sumEven[i];
        } else {
            sumEven[i+1] = sumEven[i] + a[i];
            sumOdd[i+1] = sumOdd[i];
        }
    }

    unordered_map<ll, ll> diffMap;
    for (ll i = 0; i <= n; ++i) {
        ll diff = sumEven[i] - sumOdd[i];
        ++diffMap[diff];
    }

    ll ans = 0;
    for (const auto &[_, count] : diffMap) {
        ans += count * (count - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}