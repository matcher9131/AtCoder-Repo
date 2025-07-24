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
#include <atcoder/dsu>
using namespace std;
using ll = long long;


int main() {
    ll n, m;
    cin >> n >> m;
    atcoder::dsu d(n);
    vector<vector<ll>> lang(m);
    for (ll i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; ++j) {
            ll l;
            cin >> l;
            --l;
            lang[l].push_back(i);
        }
    }

    for (const auto &v : lang) {
        for (ll i = 0; i < (ll)v.size() - 1; ++i) {
            d.merge(v[i], v[i+1]);
        }
    }

    cout << ((int)d.groups().size() == 1 ? "YES" : "NO") << endl;

    return 0;
}