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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    ll ans = 0;
    function<void(ll, int, int)> search = [&](ll acc, int i, int rest) {
        if (rest == 0) {
            ans = max(ans, acc);
        } else if (i < n) {
            search(acc ^ a[i], i+1, rest-1);
            search(acc, i+1, rest);
        }
    };

    if (k <= n-k) {
        search(0, 0, k);
    } else {
        search(accumulate(a.begin(), a.end(), 0LL, [](ll acc, ll val) { return acc ^ val; }), 0, n-k);
    }
    
    cout << ans << endl;
    return 0;
}