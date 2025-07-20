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
    vector<int> r(n), c(n);
    vector<tuple<int, int, ll>> cells(n);
    for (int i = 0; i < n; ++i) {
        int ri, ci;
        ll xi;
        cin >> ri >> ci >> xi;
        r[i] = ri;
        c[i] = ci;
        cells[i] = { ri, ci, xi };
    }

    sort(r.begin(), r.end());
    sort(c.begin(), c.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    
    vector<pair<ll, int>> sr(n), sc(n);
    for (int i = 0; i < n; ++i) {
        sr[i].second = i;
        sc[i].second = i;
    }
    unordered_map<int, unordered_map<int, ll>> m;
    for (auto &[ri, ci, xi] : cells) {
        int rj = lower_bound(r.begin(), r.end(), ri) - r.begin();
        int cj = lower_bound(c.begin(), c.end(), ci) - c.begin();
        m[rj][cj] = xi;
        sr[rj].first += xi;
        sc[cj].first += xi;
    }
    sort(sr.begin(), sr.end(), greater<pair<ll, int>>());
    sort(sc.begin(), sc.end(), greater<pair<ll, int>>());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll val = m[sr[i].second][sc[j].second];
            ans = max(ans, sr[i].first + sc[j].first - val);
            if (val == 0) break;
        }
    }

    cout << ans << endl;

    return 0;
}