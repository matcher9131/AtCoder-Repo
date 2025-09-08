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
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto nextI = [&](int ci, int val) -> int {
        for (int ni = ci + 1; ni < n; ++ni) {
            if (a[ni] >= val) return ni;
        }
        return n;
    };
    ll ans = 0;
    int i = -1;
    for (int j = 0; j < m; ++j) {
        i = nextI(i, b[j]);
        if (i == n) {
            cout << -1 << endl;
            return 0;
        }
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}