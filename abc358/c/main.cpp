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
    int n, m;
    cin >> n >> m;
    vector<unsigned> b(n);
    for (int i = 0; i < n; ++i) {
        string si;
        cin >> si;
        int bit = 0;
        for (int j = 0; j < m; ++j) {
            if (si[j] == 'o') bit |= 1U << j;
        }
        b[i] = bit;
    }

    unsigned allCorns = (1 << m) - 1;
    int ans = n;
    for (unsigned storeBit = 0; storeBit < 1U << n; ++storeBit) {
        unsigned cornBit = 0;
        for (int i = 0; i < n; ++i) {
            if (storeBit & 1U << i) cornBit |= b[i];
        }
        if (cornBit == allCorns) {
            ans = min(ans, popcount(storeBit));
        }
    }

    cout << ans << endl;
    return 0;
}