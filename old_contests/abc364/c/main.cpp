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
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    int ai = 0, bi = 0;
    ll sa = 0, sb = 0;
    for (; ai < n; ++ai) {
        sa += a[ai];
        if (sa > x) break;
    }
    for (; bi < n; ++bi) {
        sb += b[bi];
        if (sb > y) break;
    }

    cout << min(min(ai, bi) + 1, n) << endl;

    return 0;
}