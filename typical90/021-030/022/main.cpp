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

ll gcd(ll x, ll y) {
    ll r = x % y;
    return r == 0 ? y : gcd(y, r);
}

int main() {
    ll a, b ,c;
    cin >> a >> b >> c;

    ll g = gcd(a, gcd(b, c));
    cout << a / g - 1 + b / g - 1 + c / g - 1 << endl;

    return 0;
}