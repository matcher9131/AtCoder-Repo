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
    ll t;
    string s;
    cin >> n >> t >> s;
    vector<ll> l, r;
    for (int i = 0; i < n; ++i) {
        ll xi;
        cin >> xi;
        (s[i] == '1' ? l : r).push_back(xi);
    }
    sort(r.begin(), r.end());

    ll ans = 0;
    for (const ll li : l) {
        ans += upper_bound(r.begin(), r.end(), li + 2 * t) - lower_bound(r.begin(), r.end(), li);
    }

    cout << ans << endl;
    return 0;
}