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
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    ll ans = x[n-1] - x[0];

    vector<ll> d(n-1);
    for (int i = 0; i < n-1; ++i) {
        d[i] = x[i+1] - x[i];
    }
    sort(d.begin(), d.end(), greater<ll>());

    for (int i = 0; i < m-1; ++i) {
        ans -= d[i];
    }

    cout << ans << endl;
    return 0;
}