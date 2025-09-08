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
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    ll sl = 0, sr = 0;
    for (int i = 0; i < n; ++i) {
        sl += l[i];
        sr += r[i];
    }

    if (sl <= 0 && sr >= 0) {
        cout << "Yes" << endl;
        ll diff = 0 - sl;
        for (int i = 0; i < n; ++i) {
            ll d = min(diff, r[i] - l[i]);
            cout << l[i] + d << " \n"[i == n - 1];
            diff -= d;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}