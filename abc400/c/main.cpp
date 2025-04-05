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
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll y = 2; y <= n; y <<= 1) {
        ll left = 1;
        ll right = (ll)sqrtl(n / y) + 1;
        while (right - left > 1) {
            ll mid = left + (right - left) / 2;
            if (y * mid * mid <= n) {
                left = mid;
            } else {
                right = mid;
            }
        }
        ans += (left + 1) / 2;
    }

    cout << ans << endl;

    return 0;
}