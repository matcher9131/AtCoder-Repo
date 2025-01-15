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

    ll sqrtn = (ll)sqrt((double)n);

    unsigned int np = 0;
    for (ll p = 2; p <= sqrtn; ++p) {
        while (n % p == 0) {
            ++np;
            n /= p;
        }
        if (n == 1) break;
    }
    if (n > 1) ++np;

    int ans = countr_zero(bit_ceil(np));
    cout << ans << endl;
    
    return 0;
}