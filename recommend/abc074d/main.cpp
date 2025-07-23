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
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<bool>> exists(n, vector<bool>(n, true));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (k == i) continue;
            for (int j = 0; j < n; ++j) {
                if (k == j) continue;
                if (i == j) continue;
                if (a[i][j] > a[i][k] + a[k][j]) {
                    cout << -1 << endl;
                    return 0;
                } else if (a[i][j] == a[i][k] + a[k][j]) {
                    exists[i][j] = false;
                }
            }
        }
    }
    
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            if (exists[i][j]) ans += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}