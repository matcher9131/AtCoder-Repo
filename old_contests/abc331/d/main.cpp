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
    int n, nq;
    cin >> n >> nq;
    vector<string> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<vector<ll>> s(n+1, vector<ll>(n+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + (p[i][j] == 'B' ? 1 : 0);
        }
    }

    auto count = [&](int i, int j) -> ll {
        if (i < 0 || j < 0) return 0;
        ll qi = i / n;
        ll ri = i % n;
        ll qj = j / n;
        ll rj = j % n;
        return qi * qj * s[n][n] + qi * s[n][rj+1] + qj * s[ri+1][n] + s[ri+1][rj+1];
    };

    while (nq--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = count(c, d) - count(a-1, d) - count(c, b-1) + count(a-1, b-1);
        cout << ans << endl;
    }

    return 0;
}