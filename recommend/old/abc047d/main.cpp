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
    ll n, t;
    cin >> n >> t;
    set<pair<ll, ll>, greater<pair<ll, ll>>> s;
    vector<set<pair<ll, ll>>::iterator> a(n);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        auto it = s.emplace(ai, i);
        a[i] = it.first;
    }

    map<ll, set<ll>> m;
    for (ll i = 0; i < n-1; ++i) {
        ll buy = a[i]->first;
        auto [sell, sellIndex] = *s.begin();
        if (sell - buy > 0) {
            m[sell - buy].insert(sellIndex);
        }
        s.erase(a[i]);
    }

    auto it = m.end();
    --it;
    cout << it->second.size() << endl;
    return 0;
}