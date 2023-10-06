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
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    if (a / g > 1'000'000'000'000'000'000LL / b) cout << "Large" << endl;
    else cout << a / g * b << endl;

    return 0;
}