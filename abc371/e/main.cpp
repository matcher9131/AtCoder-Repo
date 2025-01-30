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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll max = 0;
    for (int i = 1; i <= n; ++i) {
        max += (ll)i * (i + 1) / 2;
    }

    vector<int> before(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        if (before[a[i]] >= 0) {
            max -= (ll)(before[a[i]] + 1) * (n - i);
        }
        before[a[i]] = i;
    }

    cout << max << endl;

    return 0;
}