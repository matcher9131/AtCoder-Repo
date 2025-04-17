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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    int remain = k;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= remain) {
            remain -= a[i];
        } else {
            ++ans;
            remain = k - a[i];
        }
    }
    if (remain < k) {
        ++ans;
    }

    cout << ans << endl;
    return 0;
}