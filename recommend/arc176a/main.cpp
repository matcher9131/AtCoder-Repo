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
    ll n, m;
    cin >> n >> m;
    set<ll> s;
    for (ll i = 0; i < m; ++i) {
        ll ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        s.insert((ai + bi) % n);
    }
    while ((ll)s.size() < m) {
        for (ll i = 0; i < m; ++i) {
            if (!s.contains(i)) {
                s.insert(i);
                break;
            }
        }
    }

    cout << n * m << endl;
    for (const ll k : s) {
        for (ll i = 0; i < n; ++i) {
            ll j = k - i;
            if (j < 0) j += n;
            cout << i+1 << " " << j+1 << endl;
        }
    }

    return 0;
}