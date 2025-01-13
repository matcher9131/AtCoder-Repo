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
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    auto mid = [](vector<ll>& v) {
        if (v.size() % 2 == 0) {
            int i = v.size() / 2;
            return (v[i-1] + v[i]) / 2;
        } else {
            return v[(v.size() - 1) / 2];
        }
    };
    
    ll midX = mid(x);
    ll midY = mid(y);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(x[i] - midX);
        ans += abs(y[i] - midY);
    }

    cout << ans << endl;

    return 0;
}