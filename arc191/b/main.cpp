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
#include <bitset>
using namespace std;
using ll = long long;

void solve() {
    unsigned n, k;
    cin >> n >> k;
    --k;

    int width = bit_width(n);
    vector<int> zeros;
    for (int i = 0; i < width; ++i) {
        if ((n & 1U << i) == 0) {
            zeros.push_back(i);
        }
    }
    
    if (k >= (1U << zeros.size())) {
        cout << -1 << endl;
        return;
    }

    unsigned ans = n;
    for (int i = 0; i < zeros.size(); ++i) {
        if (k & 1U << i) {
            ans |= 1U << zeros[i];
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}