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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;


int main() {
    int n;
    cin >> n;
    vector<pair<int, bool>> t(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }

    t[0].second = true;
    for (int i = 1; i < n; ++i) {
        if (t[i].first > t[i - 1].first) t[i].second = true;
    }
    a[n - 1].second = true;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i].first > a[i + 1].first) a[i].second = true;
    }

    mint ans = 1;
    for (int i = 0; i < n; ++i) {
        if (t[i].second) {
            // x[i] = t[i] <= a[i]
            if (t[i].first > a[i].first) {
                cout << 0 << endl;
                return 0;
            }
        } else if (a[i].second) {
            // x[i] = a[i] <= t[i]
            if (t[i].first < a[i].first) {
                cout << 0 << endl;
                return 0;
            }
        } else {
            ans *= min(t[i].first, a[i].first);
        }
    }

    cout << ans.val() << endl;

    return 0;
}