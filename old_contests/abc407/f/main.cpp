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
#include <atcoder/segtree>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<ll, int>> aDesc(n);
    for (int i = 0; i < n; ++i) {
        aDesc[i] = {a[i], i};
    }
    sort(aDesc.begin(), aDesc.end(), greater<pair<ll, int>>());

    vector<int> l(n), r(n);
    set<int> used{-1, n};
    for (const auto &[_, i] : aDesc) {
        auto itr = used.lower_bound(i);
        auto itl = itr;
        --itl;
        l[i] = i - *itl - 1;
        r[i] = *itr - i - 1;
        used.insert(i);
    }

    vector<ll> b(n+2);
    for (int i = 0; i < n; ++i) {
        b[0] += a[i];
        b[l[i] + 1] -= a[i];
        b[r[i] + 1] -= a[i];
        b[l[i] + r[i] + 2] += a[i];
    }
    for (int c = 0; c < 2; ++c) {
        for (int j = 1; j < n+2; ++j) {
            b[j] += b[j-1];
        }
    }

    for (int k = 0; k < n; ++k) {
        cout << b[k] << endl;
    }
    
    return 0;
}