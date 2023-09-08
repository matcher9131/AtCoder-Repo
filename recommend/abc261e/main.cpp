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
using namespace std;
using ll = long long;


int main() {
    int n;
    unsigned c;
    cin >> n >> c;
    vector<unsigned> t(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> a[i];
    }

    unsigned one = UINT_MAX, zero = 0;

    for (int i = 0; i < n; ++i) {
        if (t[i] == 1U) {
            one &= a[i];
            zero &= a[i];
        } else if (t[i] == 2U) {
            one |= a[i];
            zero |= a[i];
        } else if (t[i] == 3U) {
            one ^= a[i];
            zero ^= a[i];
        }
        unsigned nc = 0;
        for (int bit = 0; bit < 30; ++bit) {
            unsigned mask = 1U << bit;
            nc |= (c & mask) ? (one & mask) : (zero & mask);
        }
        c = nc;
        cout << c << endl;
    }

    return 0;
}