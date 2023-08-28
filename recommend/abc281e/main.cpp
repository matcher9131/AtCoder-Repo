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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> b(m);
    for (int i = 0; i < m; ++i) {
        b[i] = a[i];
    }
    sort(b.begin(), b.end());

    ll answer = 0;
    multiset<ll> l, r;
    for (int i = 0; i < k; ++i) {
        answer += b[i];
        l.insert(b[i]);
    }
    for (int i = k; i < m; ++i) {
        r.insert(b[i]);
    }

    cout << answer;

    for (int i = 1; i < n - m + 1; ++i) {
        auto rl = l.find(a[i - 1]);
        if (rl != l.end()) {
            l.erase(rl);
            answer -= a[i - 1];
        } else {
            r.erase(r.find(a[i - 1]));
        }

        auto il = l.upper_bound(a[i + m - 1]);
        if (il != l.end()) {
            l.emplace_hint(il, a[i + m - 1]);
            answer += a[i + m - 1];
        } else {
            r.insert(a[i + m - 1]);
        }

        if (l.size() > k) {
            auto it = l.end();
            --it;
            int t = *it;
            l.erase(it);
            answer -= t;
            r.emplace_hint(r.begin(), t);
        } else if (l.size() < k) {
            auto it = r.begin();
            int t = *it;
            r.erase(it);
            l.insert(t);
            answer += t;
        }

        cout << " " << answer;
    }
    cout << endl;

    return 0;
}