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
    cin >> n;
    int m = 46;
    vector<ll> ra(m), rb(m), rc(m);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        ++ra[ai % m];
    }
    for (int i = 0; i < n; ++i) {
        int bi;
        cin >> bi;
        ++rb[bi % m];
    }
    for (int i = 0; i < n; ++i) {
        int ci;
        cin >> ci;
        ++rc[ci % m];
    }

    ll ans = 0;
    for (int ai = 0; ai < m; ++ai) {
        for (int bi = 0; bi < m; ++bi) {
            int ci = (2 * m - ai - bi) % m;
            ans += ra[ai] * rb[bi] * rc[ci];
        }
    }

    cout << ans << endl;

    return 0;
}