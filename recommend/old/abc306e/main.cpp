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
    int n, k, cq;
    cin >> n >> k >> cq;
    vector<int> x(cq);
    vector<ll> y(cq);
    for (int i = 0; i < cq; ++i) {
        cin >> x[i] >> y[i];
        --x[i];
    }

    vector<ll> a(n);
    multiset<ll> l, s;
    for (int i = 0; i < k; ++i) {
        l.insert(0);
    }
    for (int i = k; i < n; ++i) {
        s.insert(0);
    }
    ll ans = 0;

    for (int qi = 0; qi < cq; ++qi) {
        if (y[qi] > *l.begin()) {
            l.insert(y[qi]);
            ans += y[qi];
        } else {
            s.insert(y[qi]);
        }

        auto lit = l.find(a[x[qi]]);
        if (lit != l.end()) {
            l.erase(lit);
            ans -= a[x[qi]];
        } else {
            s.erase(s.find(a[x[qi]]));
        }
        a[x[qi]] = y[qi];

        if (l.size() > k) {
            auto it = l.begin();
            ans -= *it;
            s.insert(*it);
            l.erase(it);
        } else if (l.size() < k) {
            auto it = s.end();
            --it;
            ans += *it;
            l.insert(*it);
            s.erase(it);
        }
        cout << ans << endl;
    }

    return 0;
}