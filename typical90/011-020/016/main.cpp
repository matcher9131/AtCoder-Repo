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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll ans = 1e18;
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 10000; ++j) {
            ll rest = n - a * i - b * j;
            if (rest < 0) break;
            if (rest % c == 0) {
                ans = min(ans, i + j + rest / c);
            }
        }
    }

    cout << ans << endl;

    return 0;
}