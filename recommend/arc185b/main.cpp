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
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    ll average = sum / n;
    ll reminder = sum - average * n;

    vector<ll> goal(n);
    for (int i = 0; i < n; ++i) {
        goal[i] = average + (i < n - reminder ? 0 : 1);
    }

    ll sumExtra = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= goal[i]) {
            sumExtra += a[i] - goal[i];
        } else {
            if (sumExtra < goal[i] - a[i]) {
                cout << "No" << endl;
                return;
            } else {
                sumExtra -= goal[i] - a[i];
            }
        }
    }

    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}