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

    map<int, int> l, r;
    ++l[a[0]];
    for (int i = 1; i < n; ++i) {
        ++r[a[i]];
    }
    int ans = (int)l.size() + (int)r.size();

    for (int i = 1; i < n - 1; ++i) {
        --r[a[i]];
        if (r[a[i]] == 0) {
            r.erase(a[i]);
        }
        ++l[a[i]];
        ans = max(ans, (int)l.size() + (int)r.size());
    }

    cout << ans << endl;
    return 0;
}