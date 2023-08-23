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
using namespace std;
using ll = long long;


int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b), x(q);
    for (int i = 0; i < a; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < b; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> x[i];
    }
    s.insert(s.begin(), -2e10);
    s.push_back(3e10);
    t.insert(t.begin(), -2e10);
    t.push_back(3e10);

    for (int i = 0; i < q; ++i) {
        auto ls = lower_bound(s.begin(), s.end(), x[i]);
        auto lt = lower_bound(t.begin(), t.end(), x[i]);
        ll dsr = (*ls) - x[i];
        ll dtr = (*lt) - x[i];
        --ls;
        --lt;
        ll dsl = x[i] - (*ls);
        ll dtl = x[i] - (*lt);
        ll drr = max(dsr, dtr);
        ll drl = dsr + dtl + min(dsr, dtl);
        ll dlr = dsl + dtr + min(dsl, dtr);
        ll dll = max(dsl, dtl);
        ll dmin = min(min(min(drr, drl), dlr), dll);
        cout << dmin << endl;
    }

    return 0;
}