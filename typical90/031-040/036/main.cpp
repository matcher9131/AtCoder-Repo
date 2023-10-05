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
    int n, nq;
    cin >> n >> nq;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        int xt, yt;
        cin >> xt >> yt;
        x[i] = xt + yt;
        y[i] = xt - yt;
    }
    vector<int> q(nq);
    for (int i = 0; i < nq; ++i) {
        cin >> q[i];
        --q[i];
    }

    ll xMin = *min_element(x.begin(), x.end());
    ll xMax = *max_element(x.begin(), x.end());
    ll yMin = *min_element(y.begin(), y.end());
    ll yMax = *max_element(y.begin(), y.end());

    for (int i = 0; i < nq; ++i) {
        vector<ll> t{ abs(x[q[i]] - xMin), abs(x[q[i]] - xMax), abs(y[q[i]] - yMin), abs(y[q[i]] - yMax) };
        cout << *max_element(t.begin(), t.end()) << endl;
    }

    return 0;
}