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
    ll x;
    cin >> x;

    for (ll i = 1; ; ++i) {
        x /= i;
        if (x == 1LL) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}