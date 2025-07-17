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
    ll n, wMax;
    cin >> n >> wMax;
    vector<ll> w(n), v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    ll wMin = *min_element(w.begin(), w.end());
    vector<vector<ll>> items(4);
    for (ll i = 0; i < n; ++i) {
        items[w[i] - wMin].push_back(v[i]);
    }
    for (ll i = 0; i < 4; ++i) {
        sort(items[i].begin(), items[i].end(), greater<>());
        items[i].insert(items[i].begin(), 0);
        for (ll j = 1; j < (ll)items[i].size(); ++j) {
            items[i][j] += items[i][j-1];
        }
    }

    ll ans = 0;
    for (ll i = 0; i < (ll)items[0].size(); ++i) {
        ll ws0 = i * wMin;
        if (ws0 > wMax) break;
        for (ll j = 0; j < (ll)items[1].size(); ++j) {
            ll ws1 = j * (wMin + 1);
            if (ws0 + ws1 > wMax) break;
            for (ll k = 0; k < (ll)items[2].size(); ++k) {
                ll ws2 = k * (wMin + 2);
                ll wRest = wMax - ws0 - ws1 - ws2;
                if (wRest < 0) break;
                ll l = min(wRest / (wMin + 3), (ll)items[3].size() - 1);
                ans = max(ans, items[0][i] + items[1][j] + items[2][k] + items[3][l]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}