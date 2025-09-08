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
    vector<int> q(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i] >> r[i];
    }
    int nq;
    cin >> nq;
    for (int i = 0; i < nq; ++i) {
        int t, d;
        cin >> t >> d;
        --t;
        if (d % q[t] <= r[t]) {
            cout << d / q[t] * q[t] + r[t] << endl;
        } else {
            cout << (d / q[t] + 1) * q[t] + r[t] << endl;
        }
    }

    return 0;
}