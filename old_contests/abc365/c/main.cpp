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

constexpr ll INF = 1e9 + 2;

int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto isOK = [&](ll x) -> bool {
        return accumulate(a.begin(), a.end(), 0LL, [&](ll acc, ll value) { return acc + min(x, value); }) <= m;
    };

    ll ng = INF;
    ll ok = 0;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    if (ok == INF - 1) {
        cout << "infinite" << endl;
    } else {
        cout << ok << endl;
    }

    return 0;
}