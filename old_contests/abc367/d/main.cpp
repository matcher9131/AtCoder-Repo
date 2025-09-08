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
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> s(n);
    s[0] = a[0] % m;
    for (int i = 1; i < n; ++i) {
        s[i] = (s[i-1] + a[i]) % m;
    }

    ll ans = 0;
    vector<ll> count(m);
    for (int i = 0; i < n; ++i) {
        ans += count[s[i]];
        ans += count[(s[i] - s[n-1] + m) % m];
        ++count[s[i]];
    }

    cout << ans << endl;

    return 0;
}