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

bool hasTwoPrimes(ll x) {
    int c = 0;

    for (ll p = 2; p * p <= x; ++p) {
        if (x % p) continue;
        ++c;
        if (c > 2) return false;
        while (x % p == 0) x /= p;
    }

    return x > 1 ? c == 1 : c == 2;
}

int main() {
    int nq;
    cin >> nq;

    while (nq--) {
        ll n;
        cin >> n;

        for (ll i = (ll)sqrtl(n); i >= 2; --i) {
            if (hasTwoPrimes(i)) {
                cout << i * i << endl;
                break;
            }
        }
    }

    return 0;
}