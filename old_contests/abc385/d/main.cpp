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
    int n, m;
    ll x, y;
    cin >> n >> m >> x >> y;
    map<ll, set<ll>> hx;
    map<ll, set<ll>> hy;
    for (int i = 0; i < n; ++i) {
        ll hxi, hyi;
        cin >> hxi >> hyi;
        hx[hxi].insert(hyi);
        hy[hyi].insert(hxi);
    }
    vector<char> d(m);
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> d[i] >> c[i];
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        switch (d[i]) {
            case 'D': 
                {
                    ll newY = y - c[i];
                    auto it = hx[x].lower_bound(newY);
                    while (it != hx[x].end() && *it <= y) {
                        ++ans;
                        hy[*it].erase(x);
                        it = hx[x].erase(it);
                    }
                    y = newY;
                }
                break;
            case 'U':
                {
                    ll newY = y + c[i];
                    auto it = hx[x].lower_bound(y);
                    while (it != hx[x].end() && *it <= newY) {
                        ++ans;
                        hy[*it].erase(x);
                        it = hx[x].erase(it);
                    }
                    y = newY;
                }
                break;
            case 'L':
                {
                    ll newX = x - c[i];
                    auto it = hy[y].lower_bound(newX);
                    while (it != hy[y].end() && *it <= x) {
                        ++ans;
                        hx[*it].erase(y);
                        it = hy[y].erase(it);
                    }
                    x = newX;
                }
                break;
            case 'R':
                {
                    ll newX = x + c[i];
                    auto it = hy[y].lower_bound(x);
                    while (it != hy[y].end() && *it <= newX) {
                        ++ans;
                        hx[*it].erase(y);
                        it = hy[y].erase(it);
                    }
                    x = newX;
                }
                break;
            default:
                break;
        }
    }

    cout << x << " " << y << " " << ans << endl;

    return 0;
}