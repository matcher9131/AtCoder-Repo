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
    ll m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    if (n == 1) {
        cout << a[0][0] % m << endl;
        return 0;
    }

    vector<ll> pow10(n);
    pow10[0] = 1;
    for (int i = 1; i < n; ++i) {
        pow10[i] = pow10[i-1] * 10 % m;
    }

    vector<vector<ll>> diag(n);
    for (int bit = 0; bit < (1 << (n - 1)); ++bit) {
        ll val = a[0][0];
        int d = popcount((unsigned)bit);
        int i = 0, j = 0;
        for (int b = 0; b < n - 1; ++b) {
            val *= 10;
            if (bit & (1 << b)) {
                ++i;
            } else {
                ++j;
            }
            val += a[i][j];
            val %= m;
        }
        diag[d].push_back(val * pow10[n-1] % m);
    }

    vector<vector<ll>> diag2(n);
    for (int bit = 0; bit < (1 << (n - 1)); ++bit) {
        ll val = a[n-1][n-1];
        int d = popcount((unsigned)bit);
        int i = n-1, j = n-1;
        for (int b = 0; b < n - 2; ++b) {
            if (bit & (1 << b)) {
                --i;
            } else {
                --j;
            }
            val += a[i][j] * pow10[b+1];
            val %= m;
        }
        diag2[n - 1 - d].push_back(val);
    }
    for (int i = 0; i < n; ++i) {
        sort(diag2[i].begin(), diag2[i].end());
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (const ll d1 : diag[i]) {
            int d2i = lower_bound(diag2[i].begin(), diag2[i].end(), m - d1) - diag2[i].begin();
            if (d2i > 0) {
                ans = max(ans, d1 + diag2[i][d2i - 1]);
            }
            ans = max(ans, (d1 + diag2[i].back()) % m);
        }
    }

    cout << ans << endl;
    return 0;
}