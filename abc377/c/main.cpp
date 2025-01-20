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
    ll n;
    int m;
    cin >> n >> m;
    vector<pair<ll, ll>> kights(m);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        kights[i] = make_pair(a, b);
    }

    unordered_set<ll> ngCells;
    auto setNgCell = [&](ll i, ll j) {
        if (i >= 0 && i < n && j >= 0 && j < n) {
            ngCells.insert(i * n + j);
        }
    };
    for (const auto& [i, j] : kights) {
        setNgCell(i, j);
        setNgCell(i+2, j+1);
        setNgCell(i+2, j-1);
        setNgCell(i-2, j+1);
        setNgCell(i-2, j-1);
        setNgCell(i+1, j+2);
        setNgCell(i-1, j+2);
        setNgCell(i+1, j-2);
        setNgCell(i-1, j-2);
    }

    cout << n * n - ngCells.size() << endl;

    return 0;
}