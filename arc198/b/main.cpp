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
    int t;
    cin >> t;
    while (t--) {
        ll x, y, z;
        cin >> x >> y >> z;
        cout << (x >= z && 2*x >= y && (z > 0 || y % 2 == 0) ? "Yes" : "No") << endl;
    }

    return 0;
}