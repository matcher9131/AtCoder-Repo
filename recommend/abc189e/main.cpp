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

vector<vector<ll>> prod(const vector<vector<ll>> &x, const vector<vector<ll>> &y) {
    vector<vector<ll>> res(x.size(), vector<ll>(y[0].size()));
    for (size_t i = 0; i < x.size(); ++i) {
        for (size_t j = 0; j < y[0].size(); ++j) {
            for (size_t k = 0; k < x[0].size(); ++k) {
                res[i][j] += x[i][k] * y[k][j];
            }
        }
    }
    return res;
}


int main() {
    vector<vector<ll>> op1{{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    vector<vector<ll>> op2{{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};

    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    ll m;
    cin >> m;
    vector<vector<vector<ll>>> matrix(m+1);
    matrix[0] = {{1,0,0}, {0,1,0}, {0,0,1}};
    for (ll i = 0; i < m; ++i) {
        int k;
        cin >> k;
        if (k == 1) {
            matrix[i+1] = prod(op1, matrix[i]);
        } else if (k == 2) {
            matrix[i+1] = prod(op2, matrix[i]);
        } else if (k == 3) {
            ll p;
            cin >> p;
            vector<vector<ll>> op{{-1,0,2*p}, {0,1,0}, {0,0,1}};
            matrix[i+1] = prod(op, matrix[i]);
        } else {
            ll p;
            cin >> p;
            vector<vector<ll>> op{{1,0,0}, {0,-1,2*p}, {0,0,1}};
            matrix[i+1] = prod(op, matrix[i]);
        }
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll a, b;
        cin >> a >> b;
        --b;
        vector<vector<ll>> v{{x[b]}, {y[b]}, {1}};
        auto ans = prod(matrix[a], v);
        cout << ans[0][0] << " " << ans[1][0] << endl;
    }

    return 0;
}