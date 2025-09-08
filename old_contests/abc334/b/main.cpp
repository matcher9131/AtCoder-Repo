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
    ll a, m, l, r;
    cin >> a >> m >> l >> r;

    ll kMax = r-a > 0 ? (r - a) / m : (r - a - m + 1) / m;
    ll kMin = l-a > 0 ? (l - a + m - 1) / m : (l - a) / m;
    cout << kMax - kMin + 1 << endl;

    return 0;
}