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

inline ll getSigned(ll value, bool sign) {
    return sign ? -value : value;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }

    ll ans = 0;
    for (int sx = 0; sx < 2; ++sx) {
        for (int sy = 0; sy < 2; ++sy) {
            for (int sz = 0; sz < 2; ++sz) {
                vector<ll> values(n);
                for (int i = 0; i < n; ++i) {
                    values[i] = getSigned(x[i], sx) + getSigned(y[i], sy) + getSigned(z[i], sz);
                }
                sort(values.begin(), values.end(), greater<ll>());
                ans = max(ans, accumulate(values.begin(), values.begin() + m, 0LL));
            }
        }
    }

    cout << ans << endl;
    return 0;
}