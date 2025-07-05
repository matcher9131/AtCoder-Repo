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

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a[i] = { abs(ai), ai };
    }
    sort(a.begin(), a.end());

    if (a[0].first == a[1].first) {
        int numNegative = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].first != a[0].first) {
                cout << "No" << endl;
                return;
            }
            if (a[i].second < 0) ++numNegative;
        }
        cout << (numNegative == 0 || numNegative == n / 2 || numNegative == (n+1)/2 || numNegative == n ? "Yes" : "No") << endl;
    } else {
        for (int i = 0; i < n-2; ++i) {
            if (a[i].second * a[i+2].second != a[i+1].second * a[i+1].second) {
                cout << "No" << endl;
                return;
            }
        }

        cout << "Yes" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}