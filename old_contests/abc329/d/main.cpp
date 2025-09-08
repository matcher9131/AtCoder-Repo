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
    vector<ll> a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }

    auto f = [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        return x.first == y.first ? x.second < y.second : x.first > y.first;
    };
    set<pair<ll, ll>, decltype(f)> s(f);
    vector<set<pair<ll, ll>>::iterator> its(n);
    for (ll i = 0; i < n; ++i) {
        auto [it, _] = s.emplace(0, i);
        its[i] = it;
    }

    for (ll i = 0; i < m; ++i) {
        ll old = its[a[i]]->first;
        s.erase(its[a[i]]);
        auto [nit, _] = s.emplace(old + 1, a[i]);
        its[a[i]] = nit;
        cout << s.begin()->second + 1 << endl;
    }

    return 0;
}