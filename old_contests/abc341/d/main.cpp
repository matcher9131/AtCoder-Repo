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
    ll n, m, k;
    cin >> n >> m >> k;
    --k;

    ll g = gcd(n, m);
    ll l = n * m / g;

    ll b = l/n + l/m - 2;
    ll q = k / b;
    ll r = k % b;

    ll i = n, j = m;
    ll cur = 0;
    for (ll k = 0; k <= r; ++k) {
        if (i < j) {
            cur = i;
            i += n;
        } else {
            cur = j;
            j += m;
        }
    }

    cout << q * l + cur << endl;

    return 0;
}